#pragma once

#include <time.h>

#include "NetworkBuffer.h"
#include "NetworkIds.h"

#include "PlayerInfo.h"
#include "Keepalive.h"
#include "Chat.h"
#include "ChatBroadcast.h"
#include "ServerError.h"

/**
 * @class Connection
 * @author John
 * @date 12/19/15
 * @file Connection.h
 * @brief This class is used to manage input/output/timeout of a connection
 */
class Connection
{
private:
	NetworkBuffer input;
	NetworkBuffer output;
	const int clientDesc;
	time_t lastKeepalive;
	volatile bool closed;
	PlayerInfo playerInfo;
	
public:
	Connection(int clientDesc);
	~Connection();
	
	NetworkBuffer& GetOutput();
	NetworkBuffer& GetInput();
	
	void Task();
	void ReceiveInput();
	void SendOutput();
	bool IsOpen();
	void Close();
	
	bool OnPlayerInfo();
	bool OnKeepalive();
	bool OnChat();
};
