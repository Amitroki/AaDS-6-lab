#include <iostream>
#include <vector>

using namespace std;

namespace own_graph {
	template<typename T>
	struct Edge {
		T start;
		T end;
		double weight;
		Edge(size_t first, size_t second, double way = 0): start(first), end(second) {
			if (way != 0) weight = way;
		}
	};
	template<typename T>
	class Graph {
	private:
		vector<T> _vertices;
		vector<Edge<T>> _edges;
	public:
		Graph(): _vertices(vector<T>), _edges(vector<Edge<T>>) {}
	};
}