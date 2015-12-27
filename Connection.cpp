#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "ConnectionManager.h"
#include "Connection.h"
#include "NetworkIds.h"

/**
 * @brief Initializes the socket descriptor to a previously opened socket descriptor
 *        and updates the last keepalive time
 * @param clientDesc: previously opened client socket descriptor
 */
Connection::Connection(int clientDesc):
	clientDesc(clientDesc),
	closed(false)
{
	ConnectionManager::RegisterConnection(this);
	time(&this->lastKeepalive);
}

/**
 * @brief Unregisters the connection so that it
 * no longer accepts broadcast anything. Also
 * closes the connection.
 */
Connection::~Connection()
{
	ConnectionManager::UnregisterConnection(this);
	close(this->clientDesc);
}


/**
 * @brief Getter for the output.
 * @return the output network buffer
 */
NetworkBuffer& Connection::GetOutput()
{
	return this->output;
}

/**
 * @brief Getter for the input.
 * @return the input network buffer
 */
NetworkBuffer& Connection::GetInput()
{
	return this->input;
}

/**
 * @brief Attempts to read and parse all the input
 * and send all the output.
 */
void Connection::Task()
{
	this->ReceiveInput();
	this->SendOutput();
}


/**
 * @brief Attempts to read the data waiting in the socket input buffer
 * and parse the it.
 */
void Connection::ReceiveInput()
{
	NetworkId_t currentId = NetworkId::NO_ID;
	const int ID_SIZE = sizeof(currentId);
	int bytesAvailable;
	
	// If we can read how many bytes are available
	if (ioctl(this->clientDesc, FIONREAD, &bytesAvailable) != -1)
	{
		// If any bytes are available
		if (bytesAvailable > 0)
		{
			// Read the bytes into a temp buffer
			char* socketBuffer = new char[bytesAvailable];
			ssize_t bytesRead = recv(this->clientDesc, socketBuffer, bytesAvailable, 0);
			
			// If we read any bytes
			if (bytesRead > 0)
			{
				// Copy the bytes into the input network buffer
				this->input.Push(socketBuffer, bytesRead);
			}
			
			// Clean up the temp buffer
			delete[] socketBuffer;
		}
		
		// While parsing has not failed and we have can read a network Id
		bool parsed = true;
		while (parsed && this->input.GetSize() >= ID_SIZE)
		{
			// Peek the ID
			NetworkBuffer proxy;
			proxy.Push(this->input.GetBuffer(), ID_SIZE);
			proxy >> currentId;
			
			// What is the ID
			switch (currentId)
			{
				case NetworkId::KEEPALIVE:
				{
					puts("Got KEEPALIVE");
					parsed = this->OnKeepalive();
					break;
				}
				case NetworkId::CHAT:
				{
					puts("Got CHAT");
					parsed = this->OnChat();
					break;
				}
				case NetworkId::PLAYER_INFO:
				{
					puts("Got PLAYER_INFO");
					parsed = this->OnPlayerInfo();
					break;
				}
				case NetworkId::SERVER_ERROR:
				{
					puts("Got SERVER_ERROR");
					parsed = false;
					break;
				}
				case NetworkId::CHAT_BROADCAST:
				{
					puts("Got CHAT_BROADCAST");
					parsed = false;
					break;
				}
				case NetworkId::MOVE_REQUEST:
				{
					puts("Got MOVE_REQUEST");
					parsed = false;
					break;
				}
				case NetworkId::MOVE_RESPONSE:
				{
					puts("Got MOVE_RESPONSE");
					parsed = false;
					break;
				}
				// None of the above
				default:
				{
					// We could not parse it
					puts("Got Unknown");
					parsed = false;
					break;
				}
			}
			
			if (!parsed)
			{
				puts("Unable to parse.");
			}
		}
	}
}

/**
 * @brief Sends any bytes in the output buffer that it can.
 */
void Connection::SendOutput()
{
	ssize_t bytesToSend = this->output.GetSize();
	if (bytesToSend)
	{
		// Attempt to send the entire output
		ssize_t sentBytes = send(
			this->clientDesc,
			this->output.GetBuffer(),
			bytesToSend,
			0
		);
		
		// If we sent any bytes
		if (sentBytes >= 0)
		{
			// Remove those bytes from the output
			this->output.Pop(nullptr, sentBytes);
		}
	}
}

/**
 * @brief Determines if the connection has closed
 * Delays 1 cycle before actually closing the connection
 * so that a reason may be sent for the closure.
 * @return If the connection has not closed
 */
bool Connection::IsOpen()
{
	const int timeoutPeriod = 10;
	time_t now;
	time(&now);
	bool open = !this->closed;
	bool timedOut = now >= (this->lastKeepalive + timeoutPeriod);
	
	this->closed = this->closed || timedOut;
	
	if (open)
	{
		if (timedOut)
		{
			ServerError error;
			error.error = "Connection timed out.";
			
			this->output << error;
		}
		
	}
	
	return open;
}

/**
 * @brief Set the variable indicating if the connection should close to true
 */
void Connection::Close()
{	
	this->closed = true;
}

/**
 * @brief Attemps to parse the PlayerInfo object in the input buffer
 * @return If the attempt to parse was successful
 */
bool Connection::OnPlayerInfo()
{
	bool valid = this->input.GetSize() >= this->playerInfo.GetSize();
	
	if (valid)
	{
		this->input >> this->playerInfo;
		
		if (!this->playerInfo.IsValid())
		{
			ServerError serverError;
			serverError.error = "That name is invalid.";
			
			this->output << serverError;
			
			this->playerInfo.name = "";
		}
	}
	
	return valid;
}

/**
 * @brief Attemps to parse the Keepalive object in the input buffer
 * @return If the attempt to parse was successful
 */
bool Connection::OnKeepalive()
{
	Keepalive keepalive;
	bool valid = this->input.GetSize() >= keepalive.GetSize();
	
	if (valid)
	{
		this->input >> keepalive;
		
		if (keepalive.IsAlive())
		{
			time(&this->lastKeepalive);
		}
		else
		{
			this->Close();
		}
	}
	
	return valid;
}

/**
 * @brief 
 * @return If the attempt to parse was successful
 */
bool Connection::OnChat()
{
	Chat chat;
	
	bool valid = this->input.GetSize() >= chat.GetSize();
	
	if (valid)
	{
		this->input >> chat;
		if (this->playerInfo.IsValid())
		{
			ChatBroadcast broadcast;
			NetworkBuffer buffer;
			
			broadcast.message = this->playerInfo.name + ": " + chat.message;
			buffer << broadcast;
			
			ConnectionManager::Broadcast(buffer);
		}
		else
		{
			ServerError serverError;
			serverError.error = "You are not allowed to chat.";
			
			this->output << serverError;
		}
	}
	
	return valid;
}
