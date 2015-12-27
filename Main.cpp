#include <thread>
#include <stdio.h>
#include <arpa/inet.h>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "Endianness.h"
#include "Connection.h"
#include "ConnectionManager.h"

volatile static bool quit = false;
const static struct timespec WAIT_TIME = {
	.tv_sec = 0,
	.tv_nsec = 5000000
};
/**
 * @brief This function is started in a special thread.
 * getchar is blocking and will return as soon as enter is pressed
 * Once this happens quit will be set to true and the program will
 * begin shutting down.
 */
void HandleSignal()
{
	puts("Press enter at any time to close the program.");
	getchar();
	quit = true;
}

/**
 * @brief Spawns and handles a connection.
 * @param clientDesc: the handle to the socket.
 */
void OnConnection(int clientDesc)
{
	Connection connection(clientDesc);
	
	while (connection.IsOpen())
	{
		connection.Task();
		nanosleep(&WAIT_TIME, nullptr);
	}
}

/**
 * @brief Opens a socket on port 8080.
 * @param argc: Number of arguemnts.
 * @param argv: Arguements.
 * @return 0 on success, anything else on failure.
 */
int main(int argc, char** argv)
{
	int socketDesc = socket(AF_INET, SOCK_STREAM, 0);
	socklen_t sockLen;
	struct sockaddr_in server;
	struct sockaddr_in client;
	const unsigned short PORT = 8080; 
	std::vector< std::thread > threads;
	std::thread signalThread;
	
	//Create socket
	if (socketDesc != -1)
	{
		puts("Socket Created.");
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = INADDR_ANY;
		server.sin_port = ToBigEndian(PORT);
		
		//Bind
		if(bind(socketDesc, (struct sockaddr *)&server, sizeof(server)) == 0)
		{
			puts("Bound.");
			
			//Listen
			if (listen(socketDesc, 64) == 0)
			{
				//Accept and incoming connection
				puts("Listening.");
				sockLen = sizeof(struct sockaddr_in);
				
				struct timeval timeout = {
					.tv_sec = 0,
					.tv_usec = 5000
				};
				
				setsockopt(socketDesc, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
				setsockopt(socketDesc, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
				signalThread = std::thread(HandleSignal);
				
				while (!quit)
				{
					int clientDesc = accept4(socketDesc, (struct sockaddr *)&client, &sockLen, SOCK_NONBLOCK);
					if (clientDesc != -1)
					{
						threads.push_back(std::thread(OnConnection, clientDesc));
					}
					else
					{
						nanosleep(&WAIT_TIME, nullptr);
					}
				}
			}
		}
	}
	
	puts("Closing connections.");
	ConnectionManager::CloseAll();
	
	puts("Joining threads.");
	if (signalThread.joinable())
	{
		signalThread.join();
	}
	
	for (unsigned int i = 0; i < threads.size(); i++)
	{
		std::thread& thread_ = threads.at(i);
		thread_.join();
	}
	
	puts("Closing socket.");
	close(socketDesc);
	
	puts("Quitting.");
	return 0;
}
