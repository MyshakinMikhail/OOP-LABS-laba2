#include "BitString.h"
#include <algorithm>

void BitString::validateInput(const unsigned char *arr, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] != 0 && arr[i] != 1)
			throw std::invalid_argument("BitString can only contain 0 or 1");
	}
}

BitString::BitString(size_t n, unsigned char value) : size(n)
{
	if (value != 0 && value != 1)
		throw std::invalid_argument("Only 0 or 1 allowed");
	data = new unsigned char[size];
	std::fill(data, data + size, value);
}

BitString::BitString(const std::string &bits) : size(bits.size())
{
	data = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
	{
		if (bits[i] != '0' && bits[i] != '1')
			throw std::invalid_argument("Invalid character in string");
		data[i] = (bits[i] == '1') ? 1 : 0;
	}
}

BitString::BitString(const BitString &other) : size(other.size)
{
	data = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
		data[i] = other.data[i];
}

BitString::BitString(BitString &&other) noexcept : size(other.size), data(other.data)
{
	other.size = 0;
	other.data = nullptr;
}

BitString::~BitString() noexcept
{
	delete[] data;
}

size_t BitString::Length() const
{
	return size;
}

unsigned char BitString::At(size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}

BitString BitString::Add(const BitString &other) const
{
	if (size != other.size)
		throw std::invalid_argument("Sizes must match");
	BitString result(size);
	for (size_t i = 0; i < size; i++)
		result.data[i] = (data[i] + other.data[i]) % 2;
	return result;
}

BitString BitString::Subtract(const BitString &other) const
{
	return this->Add(other);
}

BitString BitString::Copy() const
{
	BitString result;
	result.size = size;
	result.data = new unsigned char[size];
	for (size_t i = 0; i < size; i++)
		result.data[i] = data[i];
	return result;
}

BitString BitString::And(const BitString &other) const
{
	if (size != other.size)
		throw std::invalid_argument("Sizes must match");
	BitString result(size);
	for (size_t i = 0; i < size; i++)
		result.data[i] = data[i] & other.data[i];
	return result;
}

BitString BitString::Or(const BitString &other) const
{
	if (size != other.size)
		throw std::invalid_argument("Sizes must match");
	BitString result(size);
	for (size_t i = 0; i < size; i++)
		result.data[i] = data[i] | other.data[i];
	return result;
}

BitString BitString::Xor(const BitString &other) const
{
	if (size != other.size)
		throw std::invalid_argument("Sizes must match");
	BitString result(size);
	for (size_t i = 0; i < size; i++)
		result.data[i] = data[i] ^ other.data[i];
	return result;
}

BitString BitString::Not() const
{
	BitString result(size);
	for (size_t i = 0; i < size; i++)
		result.data[i] = (data[i] == 0) ? 1 : 0;
	return result;
}

BitString BitString::AssignAdd(const BitString &other) const
{
	return this->Add(other);
}

BitString BitString::AssignSub(const BitString &other) const
{
	return this->Subtract(other);
}

bool BitString::IsEqual(const BitString &other) const
{
	if (size != other.size)
		return false;
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] != other.data[i])
			return false;
	}
	return true;
}

bool BitString::IsGreater(const BitString &other) const
{
	if (size != other.size)
		throw std::invalid_argument("Sizes must match");
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] > other.data[i])
			return true;
		if (data[i] < other.data[i])
			return false;
	}
	return false;
}

bool BitString::IsLess(const BitString &other) const
{
	if (size != other.size)
		throw std::invalid_argument("Sizes must match");
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] < other.data[i])
			return true;
		if (data[i] > other.data[i])
			return false;
	}
	return false;
}

std::string BitString::ToString() const
{
	std::string s;
	s.reserve(size);
	for (size_t i = 0; i < size; i++)
		s += (data[i] ? '1' : '0');
	return s;
}
