#pragma once

#include "Serializable.h"
#include "NetworkBuffer.h"
#include <string>

class ServerError : public Serializable
{
public:
	ServerError();
	std::string error;

	virtual void Deserialize(NetworkBuffer& networkBuffer);
	virtual size_t GetSize() const;
	virtual void Serialize(NetworkBuffer& networkBuffer) const;
};

