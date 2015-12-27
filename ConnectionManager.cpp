#include <vector>
#include <mutex>
#include <stddef.h>

#include "ConnectionManager.h"

static std::vector< Connection* > connections;
static std::mutex mutex_;

void ConnectionManager::RegisterConnection(Connection* connection)
{
	std::lock_guard<std::mutex> lck(mutex_);
	connections.push_back(connection);
}

void ConnectionManager::UnregisterConnection(Connection* connection)
{
	std::lock_guard<std::mutex> lck(mutex_);
	for (size_t i = 0; i < connections.size(); i++)
	{
		if (connections.at(i) == connection)
		{
			connections.erase(connections.begin() + i);
			break;
		}
	}
}

void ConnectionManager::CloseAll()
{
	std::lock_guard<std::mutex> lck(mutex_);
	for (size_t i = 0; i < connections.size(); i++)
	{
		connections.at(i)->Close();
	}
}

void ConnectionManager::Broadcast(NetworkBuffer& networkBuffer)
{
	std::lock_guard<std::mutex> lck(mutex_);
	for (size_t i = 0; i < connections.size(); i++)
	{
		connections.at(i)->GetOutput().Push(networkBuffer.GetBuffer(), networkBuffer.GetSize());
	}
}
