#pragma once

#include <mutex>
#include <string>
#include <stddef.h>
#include "Serializable.h"


/**
 * @class NetworkBuffer
 * @author John
 * @date 06/06/15
 * @file NetworkBuffer.h
 * @brief Takes either primitive types or a class which has inherited from Serializable
 * and converts it to network endian then adds it to a buffer.
 */
class NetworkBuffer
{
private:
	unsigned int size;
	char* buffer;
	std::mutex bufferMutex;

	template<class Number>
	NetworkBuffer& NetworkNumberPush(Number& data);

	template<class Number>
	NetworkBuffer& NetworkNumberPop(Number& data);

public:
	NetworkBuffer();
	NetworkBuffer(const NetworkBuffer& other);
	~NetworkBuffer();

	void Init();
	size_t GetSize() const;
	char* GetBuffer() const;
	void Clear();

	NetworkBuffer& Push(const void* data, const unsigned int size);
	NetworkBuffer& Pop(void* data, const unsigned int size);

	NetworkBuffer& operator=(const NetworkBuffer& other);

	NetworkBuffer& operator<<(const bool& data);
	NetworkBuffer& operator<<(const char& data);
	NetworkBuffer& operator<<(const unsigned char& data);
	NetworkBuffer& operator<<(const short& data);
	NetworkBuffer& operator<<(const unsigned short& data);
	NetworkBuffer& operator<<(const int& data);
	NetworkBuffer& operator<<(const unsigned int& data);
	NetworkBuffer& operator<<(const long& data);
	NetworkBuffer& operator<<(const unsigned long& data);
	NetworkBuffer& operator<<(const long long& data);
	NetworkBuffer& operator<<(const unsigned long long& data);
	NetworkBuffer& operator<<(const float& data);
	NetworkBuffer& operator<<(const double& data);
	NetworkBuffer& operator<<(const std::string& data);
	NetworkBuffer& operator<<(const Serializable& data);

	NetworkBuffer& operator>>(bool& data);
	NetworkBuffer& operator>>(char& data);
	NetworkBuffer& operator>>(unsigned char& data);
	NetworkBuffer& operator>>(short& data);
	NetworkBuffer& operator>>(unsigned short& data);
	NetworkBuffer& operator>>(int& data);
	NetworkBuffer& operator>>(unsigned int& data);
	NetworkBuffer& operator>>(long& data);
	NetworkBuffer& operator>>(unsigned long& data);
	NetworkBuffer& operator>>(long long& data);
	NetworkBuffer& operator>>(unsigned long long& data);
	NetworkBuffer& operator>>(float& data);
	NetworkBuffer& operator>>(double& data);
	NetworkBuffer& operator>>(std::string& data);
	NetworkBuffer& operator>>(Serializable& data);
};
