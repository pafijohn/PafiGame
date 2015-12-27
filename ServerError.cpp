#include "ServerError.h"

ServerError::ServerError():
	Serializable(NetworkId::SERVER_ERROR)
{
}

void ServerError::Deserialize(NetworkBuffer& networkBuffer)
{
	networkBuffer >> this->dummy >> this->error;
}

size_t ServerError::GetSize() const
{
	return sizeof(NetworkId_t) + sizeof(unsigned int);
}

void ServerError::Serialize(NetworkBuffer& networkBuffer) const
{
	networkBuffer << this->GetId() << this->error;
}
