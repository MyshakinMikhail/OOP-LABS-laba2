#include "../src/BitString.h"
#include "gtest/gtest.h"

TEST(BitStringTest, ConstructorFromString)
{
	BitString bits("10101");
	EXPECT_EQ(bits.ToString(), "10101");
	EXPECT_EQ(bits.Length(), 5);
}

TEST(BitStringTest, ConstructorWithValue)
{
	BitString bits(4, 1);
	EXPECT_EQ(bits.ToString(), "1111");
}

TEST(BitStringTest, InvalidStringInput)
{
	EXPECT_THROW(BitString("10a01"), std::invalid_argument);
}

TEST(BitStringTest, CopyConstructor)
{
	BitString a("1100");
	BitString b = a.Copy();
	EXPECT_EQ(b.ToString(), "1100");
	EXPECT_TRUE(a.IsEqual(b));
}

TEST(BitStringTest, AndOperation)
{
	BitString a("1100");
	BitString b("1010");
	BitString res = a.And(b);
	EXPECT_EQ(res.ToString(), "1000");
}

TEST(BitStringTest, OrOperation)
{
	BitString a("1100");
	BitString b("1010");
	BitString res = a.Or(b);
	EXPECT_EQ(res.ToString(), "1110");
}

TEST(BitStringTest, XorOperation)
{
	BitString a("1100");
	BitString b("1010");
	BitString res = a.Xor(b);
	EXPECT_EQ(res.ToString(), "0110");
}

TEST(BitStringTest, NotOperation)
{
	BitString a("1100");
	BitString res = a.Not();
	EXPECT_EQ(res.ToString(), "0011");
}

TEST(BitStringTest, AddOperation)
{
	BitString a("1100");
	BitString b("1010");
	BitString res = a.Add(b);
	EXPECT_EQ(res.ToString(), "0110");
}

TEST(BitStringTest, SubtractOperation)
{
	BitString a("1100");
	BitString b("1010");
	BitString res = a.Subtract(b);
	EXPECT_EQ(res.ToString(), "0110");
}

TEST(BitStringTest, Comparisons)
{
	BitString a("1100");
	BitString b("1100");
	BitString c("1000");

	EXPECT_TRUE(a.IsEqual(b));
	EXPECT_FALSE(a.IsEqual(c));

	EXPECT_TRUE(a.IsGreater(c));
	EXPECT_TRUE(c.IsLess(a));
}

TEST(BitStringTest, OutOfRangeAccess)
{
	BitString a("101");
	EXPECT_THROW(a.At(5), std::out_of_range);
}
