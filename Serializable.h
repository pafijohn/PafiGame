#pragma once

#include <stddef.h>
#include "NetworkIds.h"

class NetworkBuffer;

/**
 * @class Serializable
 * @author John
 * @date 06/06/15
 * @file Serializable.h
 * @brief A class to be used for serializing a class.
 */
class Serializable
{
private:
	const NetworkId_t networkId;
public:
	NetworkId_t dummy;
	Serializable(NetworkId_t networkId);
	
	NetworkId_t GetId() const;
	/**
	 * @brief Gets the size required to deserialize the current class.
	 */
	virtual size_t GetSize() const = 0;
	/**
	 * @brief Serializes the current class.
	 * @param networkBuffer: Buffer to push the the serialized info into.
	 */
	virtual void Serialize(NetworkBuffer& networkBuffer) const = 0;
	/**
	 * @brief Deserializes the current class.
	 * @param networkBuffer: Buffer to pop the the serialized info from.
	 */
	virtual void Deserialize(NetworkBuffer& networkBuffer) = 0;
};
