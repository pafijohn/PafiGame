#pragma once

#include "Serializable.h"
#include "NetworkBuffer.h"

class ChatBroadcast : public Serializable
{
public:
	std::string message;
	ChatBroadcast();
	
	virtual void Deserialize(NetworkBuffer& networkBuffer);
	virtual size_t GetSize() const;
	virtual void Serialize(NetworkBuffer& networkBuffer) const;
};

