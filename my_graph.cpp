#include <iostream>
#include <vector>

using namespace std;

namespace own_graph {
	template<typename Vertex, typename Distance = double>
	struct Edge {
		Vertex start;
		Vertex end;
		Distance weight;
		Edge(Vertex first, Vertex second, Distance way = 0): start(first), end(second) {
			if (way != 0) 
				weight = way;
		}
	};
	template<typename Vertex, typename Distance = double>
	class Graph {
	private:
		vector<Vertex> _vertices;
		vector<Edge<Vertex, Distance>> _edges;
	public:
		Graph(): _vertices(vector<Vertex>()), _edges(vector<Edge<Vertex, Distance>>()) {}

		bool has_vertex(const Vertex& vertex) const {
			for (size_t i = 0; i < _vertices.size(); i++) {
				if (_vertices[i] == vertex) 
					return true;
			}
			return false;
		}

		void add_vertex(const Vertex& vertex) {
			_vertices.push_back(vertex);
		}

		bool remove_vertex(const Vertex& vertex) {
			if (has_vertex(vertex)) {
				for (size_t i = 0; i < _vertices.size(); i++) {
					if (_vertices[i] == vertex) {
						_vertices.erase(_vertices.begin() + i);
						return true;
					}
				}
			}
			return false;
		}

		vector<Vertex> vertices() const {
			return _vertices;
		}

		void print_vertices() const {
			cout << "vertices in this graph:\t{";
			for (size_t i = 0; i < _vertices.size(); i++) {
				cout << ' ' << _vertices[i];
			}
			cout << " }" << endl;
		}
	};
}