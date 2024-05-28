#include <gtest/gtest.h>
#include "my_graph.cpp"

using namespace own_graph;
using namespace std;

TEST(EdgeTest, CheckingTheSetValues1) {
	Edge<int> a(0, 2);
	EXPECT_EQ(a.start, 0);
	EXPECT_EQ(a.end, 2);
}
TEST(EdgeTest, CheckingTheSetValues2) {
	Edge<int> a(0, 2, 9.0);
	EXPECT_EQ(a.start, 0);
	EXPECT_EQ(a.end, 2);
	EXPECT_NE(a.weight, 9.4);
}
TEST(EdgeTest, CheckingTheSetValues3) {
	Edge<int> a(-1, 2, -9.0);
	EXPECT_EQ(a.start, -1);
	EXPECT_EQ(a.end, 2);
	EXPECT_NE(a.weight, -9.0);
}
