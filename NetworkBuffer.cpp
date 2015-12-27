#include "NetworkBuffer.h"
#include <algorithm>
#include <string.h>
#include "Endianness.h"

/**
 * @brief Constructor which calls init.
 * @return 
 */
NetworkBuffer::NetworkBuffer()
{
	this->Init();
}

/**
 * @brief Copy Constructor which assigns this network buffer to another.
 * @param other: Other network buffer to copy from.
 * @return 
 */
NetworkBuffer::NetworkBuffer(const NetworkBuffer& other)
{
	this->Init();
	*this = other;
}

/**
 * @brief Destructor that frees memory to avoid memory leaks
 * @return 
 */
NetworkBuffer::~NetworkBuffer()
{
	this->Clear();
}

/**
 * @brief Initializes buffer and size to default values.
 */
void NetworkBuffer::Init()
{
	this->buffer = nullptr;
	this->size = 0;
}

/**
 * @brief Pushes size from data into buffer.
 * @param data: Source to copy from.
 * @param size: Number of bytes to copy from data.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::Push(const void* data, const unsigned int size)
{
	std::lock_guard<std::mutex> guard(this->bufferMutex);
	this->size += size;
	this->buffer = (char*)realloc(this->buffer, this->size);
	memcpy(&this->buffer[this->size - size], data, size);
	return *this;
}

/**
 * @brief Pops size from buffer into data.
 * @param data: Destination to pop data into.
 * @param size: Number of bytes to copy to data.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::Pop(void* data, const unsigned int size)
{
	std::lock_guard<std::mutex> guard(this->bufferMutex);
	char* newBuffer = nullptr;
	int newSize = this->size - size;

	if (this->size >= size && data != nullptr)
	{
		memcpy(data, &this->buffer[0], size);
	}

	this->size = std::max(newSize, 0);

	if (this->size)
	{
		newBuffer = (char*)malloc(this->size);
		memcpy(newBuffer, &this->buffer[size], this->size);
	}

	free(this->buffer);
	this->buffer = newBuffer;
	return *this;
}

/**
 * @brief Clears the network buffer.
 */
void NetworkBuffer::Clear()
{
	free(this->buffer);
	this->Init();
}

/**
 * @brief Pushes a primitive type into the buffer.
 * @param data: Primitive type to push into the buffer.
 * @return "*this", so as to chain this method.
 */
template<class Number>
NetworkBuffer& NetworkBuffer::NetworkNumberPush(Number& data)
{
	auto netNum = ToBigEndian(data);
	return this->Push(&netNum, sizeof(netNum));
}

/**
 * @brief Pops a primitive type from the buffer.
 * @param data: Primitive type to pop pop the buffer.
 * @return "*this", so as to chain this method.
 */
template<class Number>
NetworkBuffer& NetworkBuffer::NetworkNumberPop(Number& data)
{
	auto& ret = this->Pop(&data, sizeof(data));
	data = FromBigEndian(data);
	return ret;
}

/**
 * @brief Getter for the size of the buffer.
 * @return Size of buffer.
 */
size_t NetworkBuffer::GetSize() const
{
	return this->size;
}

/**
 * @brief Getter for the buffer.
 * @return Buffer containing data.
 */
char* NetworkBuffer::GetBuffer() const
{
	return this->buffer;
}

/**
 * @brief Copys from another network buffer into this network buffer.
 * @param other: Other network buffer to copy from.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator=(const NetworkBuffer& other)
{
	this->Clear();
	this->Push(other.GetBuffer(), other.GetSize());
	return *this;
}

/**
 * @brief Pushes a bool into the network buffer.
 * @param data: bool to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const bool& data)
{
	return this->Push(&data, sizeof(data));
}

/**
 * @brief Pushes a char into the network buffer.
 * @param data: char to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const char& data)
{
	return this->Push(&data, sizeof(data));
}

/**
 * @brief Pushes an unsigned char into the network buffer.
 * @param data: unsigned char to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const unsigned char& data)
{
	return this->Push(&data, sizeof(data));
}

/**
 * @brief Pushes a short into the network buffer.
 * @param data: short to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const short& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes an unsigned short into the network buffer.
 * @param data: unsigned short to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const unsigned short& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes an int into the network buffer.
 * @param data: int to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const int& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes an unsigned int into the network buffer.
 * @param data: unsigned int to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const unsigned int& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes a long into the network buffer.
 * @param data: long to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const long& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes an unsigned long into the network buffer.
 * @param data: unsigned long to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const unsigned long& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes a long long into the network buffer.
 * @param data: long long to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const long long& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes an unsigned long long into the network buffer.
 * @param data: unsigned long long to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const unsigned long long& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes a float into the network buffer.
 * @param data: float to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const float& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes a double into the network buffer.
 * @param data: double to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const double& data)
{
	return this->NetworkNumberPush(data);
}

/**
 * @brief Pushes a std::string into the network buffer.
 * @param data: std::string to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const std::string& data)
{
	unsigned int size = data.size();
	*this << size;
	return this->Push(data.c_str(), size);
}

/**
 * @brief Pushes a Serializable class into the network buffer.
 * @param data: Serializable class to push into the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator<<(const Serializable& data)
{
	data.Serialize(*this);
	return *this;
}

/**
 * @brief Pops a bool from the network buffer.
 * @param data: bool to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(bool& data)
{
	return this->Pop(&data, sizeof(data));
}

/**
 * @brief Pops a char from the network buffer.
 * @param data: char to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(char& data)
{
	return this->Pop(&data, sizeof(data));
}

/**
 * @brief Pops an unsigned char from the network buffer.
 * @param data: unsigned char to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(unsigned char& data)
{
	return this->Pop(&data, sizeof(data));
}

/**
 * @brief Pops a short from the network buffer.
 * @param data: short to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(short& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops an unsigned short from the network buffer.
 * @param data: unsigned short to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(unsigned short& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops an int from the network buffer.
 * @param data: int to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(int& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops an unsigned int from the network buffer.
 * @param data: unsigned int to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(unsigned int& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops a long from the network buffer.
 * @param data: long to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(long& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops an unsigned long from the network buffer.
 * @param data: unsigned long to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(unsigned long& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops a long long from the network buffer.
 * @param data: long long to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(long long& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops an unsigned long long from the network buffer.
 * @param data: unsigned long long to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(unsigned long long& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops a float from the network buffer.
 * @param data: float to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(float& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops a double from the network buffer.
 * @param data: double to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(double& data)
{
	return this->NetworkNumberPop(data);
}

/**
 * @brief Pops a std::string from the network buffer.
 * @param data: std::string to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(std::string& data)
{
	unsigned int size = 0;
	*this >> size;
	data.resize(size);
	return this->Pop((void*)data.c_str(), size);
}

/**
 * @brief Pops a Serializable class from the network buffer.
 * @param data: Serializable class to pop from the network buffer.
 * @return "*this", so as to chain this method.
 */
NetworkBuffer& NetworkBuffer::operator>>(Serializable& data)
{
	data.Deserialize(*this);
	return *this;
}
