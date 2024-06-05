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
TEST(GraphTest, CheckingTheSetValues3) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 30);
	a.add_edge(2, 5, 10);
	a.print_edges();
	a.add_edge(2, 4, 15);
	a.print_edges();
	auto b = a.edges(2);
	for (size_t i = 0; i < b.size(); i++) {
		b[i].print_edge();
	}
}
TEST(GraphTest, CheckingTheSetValues4) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 30);
	a.add_edge(2, 5, 10);
	a.print_edges();
	EXPECT_NE(2, a.degree(2));
}
TEST(GraphTest, CheckingTheSetValues5) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 30);
	a.add_edge(2, 5, 10);
	a.add_edge(1, 2, 50);
	a.add_edge(0, 5, 7);
	a.add_edge(0, 2, 7);
	auto b = a.walk(0);
}
TEST(GraphTest, CheckingTheSetValues6) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 10);
	a.add_edge(1, 5, 2);
	int result;
	auto b = a.shortest_path(0, 5);
	a.print_path(b);
}
TEST(GraphTest, CheckingTheSetValues7) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 10);
	a.add_edge(1, 5, 2);
	a.add_edge(0, 2, 3);
	a.add_edge(2, 4, 5);
	a.add_edge(4, 5, 1);
	int result;
	auto b = a.shortest_path(0, 5);
	a.print_path(b);
}
TEST(GraphTest, CheckingTheSetValues8) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 10);
	a.add_edge(1, 5, 2);
	a.add_edge(0, 2, 3);
	a.add_edge(2, 4, 5);
	a.add_edge(4, 5, 1);
	a.add_edge(0, 3, 3);
	a.add_edge(3, 4, 5);
	int result;
	auto b = a.shortest_path(0, 5);
	a.print_path(b);
	EXPECT_EQ(a.count_path(b), 9);
}
TEST(GraphTest, CheckingTheSetValues9) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(0, 1, 10);
	a.add_edge(1, 5, 2);
	a.add_edge(0, 2, 3);
	a.add_edge(2, 4, 5);
	a.add_edge(4, 5, 1);
	a.add_edge(0, 3, 3);
	a.add_edge(3, 4, 5);
	cout << "The most remote emergency room: " << a.find_the_most_remote_emergency_room() << endl;
}
TEST(GraphTest, CheckingTheSetValues10) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(1, 0, 10);
	a.add_edge(1, 5, 2);
	a.add_edge(1, 2, 3);
	a.add_edge(2, 4, 5);
	a.add_edge(4, 5, 1);
	a.add_edge(1, 3, 3);
	a.add_edge(3, 4, 5);
	cout << "The most remote emergency room: " << a.find_the_most_remote_emergency_room() << endl;
}
TEST(GraphTest, CheckingTheSetValues11) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(1, 1, 10);
	a.add_edge(1, 5, 2);
	a.add_edge(0, 2, 3);
	a.add_edge(2, 4, 5);
	a.add_edge(4, 5, 1);
	a.add_edge(0, 3, 3);
	a.add_edge(3, 4, 5);
	a.add_edge(3, 4, 90);
	cout << "The most remote emergency room: " << a.find_the_most_remote_emergency_room() << endl;
}
TEST(GraphTest, CheckingTheSetValues12) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_vertex(4);
	a.add_vertex(5);
	a.add_edge(1, 1, 10);
	a.add_edge(1, 5, 2);
	a.add_edge(0, 2, 300);
	a.add_edge(2, 4, 5);
	a.add_edge(4, 5, 1);
	a.add_edge(0, 3, 300);
	a.add_edge(3, 4, 5);
	a.add_edge(3, 4, 90);
	a.add_edge(0, 5, 100);
	cout << "The most remote emergency room: " << a.find_the_most_remote_emergency_room() << endl;
}
TEST(GraphTest, CheckingTheSetValues13) {
	Graph<int, int> a;
	a.add_vertex(0);
	a.add_vertex(1);
	a.add_vertex(2);
	a.add_vertex(3);
	a.add_edge(0, 1, 5);
	a.add_edge(0, 2, 3);
	a.add_edge(2, 1, 1);
	a.add_edge(1, 3, 4);
	a.add_edge(2, 3, 4);
	auto b = a.shortest_path(0, 3);
	a.print_path(b);
	EXPECT_EQ(a.count_path(b), 7);
}