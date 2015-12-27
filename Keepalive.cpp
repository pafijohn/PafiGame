#include "Keepalive.h"
#include "NetworkIds.h"

/**
 * @brief Initializes the value of isAlive to false
 */
Keepalive::Keepalive():
	Serializable(NetworkId::KEEPALIVE),
	isAlive(true)
{
}

/**
 * @brief Stub
 */
Keepalive::~Keepalive()
{
}

/**
 * @brief Getter for isAlive
 * @return isAlive
 */
bool Keepalive::IsAlive() const
{
	return this->isAlive;
}

/**
 * @brief Getter for the size required to deserialize the Keepalive class.
 * @return The size required to deserialize the Keepalive class.
 */
size_t Keepalive::GetSize() const
{
	return sizeof(this->isAlive);
}

/**
 * @brief Serializes the Keepalive class.
 * @param networkBuffer: Buffer to push the the Keepalive info into.
 */
void Keepalive::Serialize(NetworkBuffer& networkBuffer) const
{
	networkBuffer << this->GetId() << this->isAlive;
}

/**
 * @brief Deserializes the Keepalive class.
 * @param networkBuffer: Buffer to pop the the Keepalive info from.
 */
void Keepalive::Deserialize(NetworkBuffer& networkBuffer)
{
	networkBuffer >> this->dummy >> this->isAlive;
}