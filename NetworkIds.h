#pragma once

namespace NetworkId
{
	enum
	{
		NO_ID,
		PLAYER_INFO,
		SERVER_ERROR,
		KEEPALIVE,
		CHAT,
		CHAT_BROADCAST,
		MOVE_REQUEST,
		MOVE_RESPONSE,
		NUM_IDS
	};
}

typedef unsigned int NetworkId_t;
