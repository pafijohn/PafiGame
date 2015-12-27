#pragma once

#include "Connection.h"
#include "NetworkBuffer.h"

class ConnectionManager
{
public:
	static void RegisterConnection(Connection* connection);
	static void UnregisterConnection(Connection* connection);
	static void Broadcast(NetworkBuffer& networkBuffer);
	static void CloseAll();
};
