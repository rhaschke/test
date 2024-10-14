#include <test/main.h>
#include <gtest/gtest.h>

TEST(MsgPrinter, main)
{
	test::main m;
	m.ints = {1, 2, 3};
	m.subs.resize(2);
	std::cout << m;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
