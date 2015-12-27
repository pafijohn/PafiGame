#include "ChatBroadcast.h"

ChatBroadcast::ChatBroadcast():
	Serializable(NetworkId::CHAT_BROADCAST)
{
}

void ChatBroadcast::Deserialize(NetworkBuffer& networkBuffer)
{
	networkBuffer >> this->dummy >> this->message;
}

size_t ChatBroadcast::GetSize() const
{
	return sizeof(NetworkId_t) + sizeof(unsigned int);
}

void ChatBroadcast::Serialize(NetworkBuffer& networkBuffer) const
{
	networkBuffer << this->GetId() << this->message;
}
