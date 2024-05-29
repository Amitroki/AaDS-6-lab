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
		void print_edge() const {
			cout << start << " ---> " << end << ", weight: " << weight << endl;
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

		void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
			Edge<Vertex, Distance> new_edge(from, to, d);
			if (has_vertex(from) && has_vertex(to)) {
				_edges.push_back(new_edge);
			}
		}

		bool remove_edge(const Vertex& from, const Vertex& to) {
			for (size_t i = 0; i < _edges.size(); i++) {
				if (_edges[i].start == from && _edges[i].end == to) {
					_edges.erase(_edges.begin() + i);
					return true;
				}
			}
			return false;
		}

		bool remove_edge(const Edge<Vertex, Distance>& edge) {
			for (size_t i = 0; i < _edges.size(); i++) {
				if (_edges[i].start == edge.start && _edges[i].end == edge.end && _edges[i].weight == edge.weight) {
					_edges.erase(_edges.begin() + i);
					return true;
				}
			}
			return false;
		}

		bool has_edge(const Vertex& from, const Vertex& to) {
			for (size_t i = 0; i < _edges.size(); i++) {
				if (_edges[i].start == from && _edges[i].end == to) {
					return true;
				}
			}
			return false;
		}

		bool has_edge(const Edge<Vertex, Distance>& edge) {
			for (size_t i = 0; i < _edges.size(); i++) {
				if (_edges[i].start == edge.start && _edges[i].end == edge.end && _edges[i].weight == edge.weight) {
					return true;
				}
			}
			return false;
		}

		void print_edges() const {
			for (size_t i = 0; i < _edges.size(); i++) {
				_edges[i].print_edge();
			}
		}

		vector<Edge<Vertex, Distance>> edges(const Vertex& vertex) const {
			vector<Edge<Vertex, Distance>> result;
			for (size_t i = 0; i < _edges.size(); i++) {
				if (_edges[i].start == vertex) {
					result.push_back(_edges[i]);
				}
			}
			return result;
		}

		size_t order() const {
			return _vertices.size();
		}

		size_t degree(const Vertex& v) const {
			return edges(v).size();
		}

	};
}