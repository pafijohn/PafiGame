#pragma once

#include "NetworkBuffer.h"

class Keepalive : public Serializable
{
public:
	bool isAlive;
	Keepalive();
	~Keepalive();
	
	bool IsAlive() const;
	size_t GetSize() const;
	void Serialize(NetworkBuffer& networkBuffer) const;
	void Deserialize(NetworkBuffer& networkBuffer);
};

