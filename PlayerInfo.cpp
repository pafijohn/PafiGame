#include "PlayerInfo.h"

PlayerInfo::PlayerInfo():
	Serializable(NetworkId::PLAYER_INFO)
{
}

bool PlayerInfo::IsValid()
{
	return !!this->name.size();
}

void PlayerInfo::Deserialize(NetworkBuffer& networkBuffer)
{
	networkBuffer >> this->dummy >> this->name;
}

size_t PlayerInfo::GetSize() const
{
	return sizeof(this->dummy) + sizeof(unsigned int);
}

void PlayerInfo::Serialize(NetworkBuffer& networkBuffer) const
{
	networkBuffer << this->GetId() << this->name;
}
