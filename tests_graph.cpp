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
	EXPECT_EQ(a.weight, -9.0);
}

TEST(GraphTest, CheckingTheSetValues1) {
	Graph<int> a;
	int vertex = 0;
	a.add_vertex(vertex);
	EXPECT_TRUE(a.has_vertex(0));
	vertex = 9;
	a.add_vertex(vertex);
	EXPECT_FALSE(a.has_vertex(10));
	EXPECT_FALSE(a.has_vertex(90));
}
TEST(GraphTest, CheckingTheSetValues2) {
	Graph<int> a;
	int vertex = 0;
	a.add_vertex(vertex);
	EXPECT_TRUE(a.has_vertex(0));
	vertex = 9;
	a.add_vertex(vertex);
	EXPECT_FALSE(a.has_vertex(10));
	EXPECT_FALSE(a.has_vertex(90));
	vertex = 90;
	a.add_vertex(vertex);
	EXPECT_TRUE(a.has_vertex(90));
	a.remove_vertex(vertex);
	EXPECT_FALSE(a.has_vertex(90));
	a.print_vertices();
	a.add_vertex(10);
	a.print_vertices();
}