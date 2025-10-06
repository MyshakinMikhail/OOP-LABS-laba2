#ifndef BITSTRING_H
#define BITSTRING_H

#include <cstddef>
#include <stdexcept>
#include <string>

class BitString
{
private:
	size_t size;
	unsigned char *data;

	void validateInput(const unsigned char *arr, size_t n);

public:
	BitString();
	BitString(size_t n, unsigned char value = 0);
	BitString(const std::string &bits);
	BitString(const BitString &other);
	BitString(BitString &&other) noexcept;

	~BitString() noexcept;

	size_t Length() const;
	unsigned char At(size_t index) const;

	BitString Add(const BitString &other) const;
	BitString Subtract(const BitString &other) const;
	BitString Copy() const;

	BitString And(const BitString &other) const;
	BitString Or(const BitString &other) const;
	BitString Xor(const BitString &other) const;
	BitString Not() const;

	BitString AssignAdd(const BitString &other) const;
	BitString AssignSub(const BitString &other) const;

	bool IsEqual(const BitString &other) const;
	bool IsGreater(const BitString &other) const;
	bool IsLess(const BitString &other) const;

	std::string ToString() const;
};

#endif
