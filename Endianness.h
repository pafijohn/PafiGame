#pragma once

bool IsLittleEndian();

/**
 * @brief Swaps primitive type endian.
 * @param u: Primitive type to swap.
 * @return Swapped primitive type.
 */
template <typename T>
T SwapEndian(T u)
{
	union
	{
		T u;
		unsigned char u8[sizeof(T)];
	} source, dest;

	source.u = u;

	for (int i = 0; i < sizeof(T); i++)
	{
		dest.u8[i] = source.u8[sizeof(T) - i - 1];
	}

	return dest.u;
}

/**
 * @brief Swaps from the native endian to big endian.
 * @param native: A primitive type to swap to big endian.
 * @return The primitive type in big endian.
 */
template <typename T>
T ToBigEndian(T native)
{
	T network;
	if (IsLittleEndian())
	{
		network = SwapEndian(native);
	}
	else
	{
		network = native;
	}
	
	return network;
}

/**
 * @brief Swaps from the big endian to native endian.
 * @param native: A primitive type to swap to native endian.
 * @return The primitive type in native endian.
 */
template <typename T>
T FromBigEndian(T network)
{
	return ToBigEndian(network);
}
