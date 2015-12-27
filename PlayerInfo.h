#pragma once

#include <string>
#include "Serializable.h"
#include "NetworkBuffer.h"

class PlayerInfo : public Serializable
{
public:
	std::string name;
	PlayerInfo();
	
	bool IsValid();
	virtual void Deserialize(NetworkBuffer& networkBuffer);
	virtual size_t GetSize() const;
	virtual void Serialize(NetworkBuffer& networkBuffer) const;
};

