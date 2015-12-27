#include "NetworkBuffer.h"
#include "Chat.h"

/**
 * @brief Stub
 */
Chat::Chat():
	Serializable(NetworkId::CHAT)
{
}

/**
 * @brief Getter for the size required to deserialize the Chat class.
 * @return The size required to deserialize the Chat class.
 */
size_t Chat::GetSize() const
{
	return sizeof(NetworkId_t) + sizeof(unsigned int);
}

/**
 * @brief Serializes the Chat class.
 * @param networkBuffer: Buffer to push the the Chat info into.
 */
void Chat::Serialize(NetworkBuffer& networkBuffer) const
{
	networkBuffer << this->GetId() << this->message;
}

/**
 * @brief Deserializes the Chat class.
 * @param networkBuffer: Buffer to pop the the Chat info from.
 */
void Chat::Deserialize(NetworkBuffer& networkBuffer)
{
	networkBuffer >> this->dummy >> this->message;
}
