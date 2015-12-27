#include "Serializable.h"

Serializable::Serializable(NetworkId_t networkId):
	networkId(networkId),
	dummy(NetworkId::NO_ID)
{
	
}

NetworkId_t Serializable::GetId() const
{
	return this->networkId;
}