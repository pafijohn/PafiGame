#pragma once

#include <string>
#include "Serializable.h"

/**
 * @class Chat
 * @author John
 * @date 19/12/15
 * @file Chat.h
 * @brief Serializable class that is used for messaging.
 */
class Chat: public Serializable
{
public:
	std::string message;
	Chat();
	
	virtual size_t GetSize() const;
	virtual void Serialize(NetworkBuffer& networkBuffer) const;
	virtual void Deserialize(NetworkBuffer& networkBuffer);
};

