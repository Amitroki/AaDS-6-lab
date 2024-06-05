#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <exception>
#include <map>

using namespace std;

namespace own_graph {
	template<typename Vertex, typename Distance = double>
	struct Edge {
		Vertex start;
		Vertex end;
		Distance weight;
		Edge(Vertex first, Vertex second, Distance way = 0): start(first), end(second), weight(way) {}
		void print_edge() const {
			cout << start << " ---> " << end << ", weight: " << weight << endl;
		}
	};
	template<typename Vertex, typename Distance = double>
	class Graph {
	private:
		vector<Vertex> _vertices;
		vector<Edge<Vertex, Distance>> _edges;
		const int inf = numeric_limits<Distance>::max();
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
						for (int j = 0; j < _edges.size(); j++) {
							if (_edges[j].start == vertex || _edges[j].end == vertex) {
								remove_edge(_edges[j]);
								j--;
							}
						}
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

		bool has_edge(const Vertex& from, const Vertex& to) const {
			for (size_t i = 0; i < _edges.size(); i++) {
				if (_edges[i].start == from && _edges[i].end == to) {
					return true;
				}
			}
			return false;
		}

		Distance give_the_distance_of_the_edge(const Vertex& from, const Vertex& to) const {
			if (has_edge(from, to)) {
				for (size_t i = 0; i < _edges.size(); i++) {
					if (_edges[i].start == from && _edges[i].end == to) {
						return _edges[i].weight;
					}
				}
			}
			return inf;
		}

		bool has_edge(const Edge<Vertex, Distance>& edge) const {
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

		vector<Vertex> adjacent(const Vertex& vertex) const {
			vector<Edge<Vertex, Distance>> edg = edges(vertex);
			vector<Vertex> result;
			for (auto& element : edg) {
				result.push_back(element.end);
			}
			return result;
		}

		size_t order() const {
			return _vertices.size();
		}

		size_t degree(const Vertex& v) const {
			return edges(v).size();
		}

		vector<Vertex> walk(const Vertex& vert) const {
			queue<Vertex> good_queue;
			good_queue.push(vert);
			vector<Vertex> result;

			unordered_map<Vertex, bool> visited_vertices;
			for (auto& one_vertex : _vertices) {
				visited_vertices[one_vertex] = false;
			}
			visited_vertices[vert] = true;

			while (!good_queue.empty()) {
				Vertex element = good_queue.front();
				good_queue.pop();
				for (auto& edge : edges(element)) {
					if (!visited_vertices[edge.end]) {
						good_queue.push(edge.end);
						result.push_back(edge.end);
						visited_vertices[edge.end] = true;
						cout << edge.end << " ";
					}
				}
				cout << endl;
				visited_vertices[element] = true;
			}
			return result;
		}

		bool is_there_negative_weight() const {
			for (const auto& edge : _edges) {
				if (edge.weight < 0) return true;
			}
			return false;
		}

		/*pair<map<Vertex, Distance>, map<Vertex, Vertex>>  dijkstras_algorithm(const Vertex& from) const {
			if (is_there_negative_weight())
				throw("Dijkstras algorithm can't be used for graph with negative edge's weight!");

			vector<Vertex> for_visit = vertices();
			map<Vertex, Distance> shortest_distance;
			map<Vertex, Vertex> way;

			for (const Vertex& vertex : for_visit) {
				shortest_distance[vertex] = inf;
			}
			shortest_distance[from] = 0;

			while (!for_visit.empty()) {
				Vertex vertex = for_visit[0];
				vector<Vertex> neighbours = adjacent(vertex);
				for (const Vertex& neighbour : neighbours) {
					Distance current_weight = shortest_distance[vertex] + give_the_distance_of_the_edge(vertex, neighbour);
					cout << current_weight << endl;
					if (current_weight < shortest_distance[neighbour]) {
						shortest_distance[neighbour] = current_weight;
						way[neighbour] = vertex;
					}
				}
				size_t i = 0;
				for (; i < for_visit.size(); i++) {
					if (for_visit[i] == vertex)
						break;
				}
				for_visit.erase(for_visit.begin() + i);
			}
			return pair(shortest_distance, way);
		}*/

		pair<vector<Distance>, vector<Vertex>> dijkstras_algorithm(const Vertex& from) const {
			if (is_there_negative_weight())
				throw("Dijkstras algorithm can't be used for graph with negative edge's weight!");
			vector<Distance> d(_vertices.size(), inf);
			vector<Vertex> prev(_vertices.size(), NULL);
			d[from] = 0;
			vector<Vertex> q;
			q.push_back(from);
			while (!q.empty()) {
				sort(q.begin(), q.end());
				auto u = q.front();
				q.erase(q.begin());
				for (const auto& e : _edges) {
					if (e.start == u) {
						auto v = e.end;
						auto weight = e.weight;
						if (d[v] > d[u] + weight && d[v] != -1) {
							d[v] = d[u] + weight;
							prev[v] = u;
							q.push_back(v);
						}
					}
				}
			}
			return make_pair(d, prev);
		}

		void print_path(vector<Vertex>& path) const {
			cout << path[0];
			for (size_t i = 1; i < path.size(); i++) {
				cout << " --> " << path[i];
			}
			cout << " ( " << count_path(path) << " )" << endl;
		}

		Distance count_path(vector<Vertex>& path) const {
			Distance result_distance = 0;
			for (size_t i = 0; i < path.size() - 1; i++) {
				result_distance += give_the_distance_of_the_edge(path[i], path[i + 1]);
			}
			return result_distance;
		}

		Edge<Vertex, Distance> get_edge(const Vertex& from, const Vertex& to) const {
			for (const Edge<Vertex, Distance>& edge : _edges) {
				if (edge.start == from && edge.end == to)
					return edge;
			}
			throw("There is no edge in graph!");
		}

		/*vector<Edge<Vertex, Distance>> shortest_path(const Vertex& from, const Vertex& to) const {

			if (from == to)
				return vector<Edge<Vertex, Distance>>();

			auto p = dijkstras_algorithm(from);
			map<Vertex, Distance> shortest = p.first;
			map<Vertex, Vertex> way = p.second;
			vector<Edge<Vertex, Distance>> final_path;
			Vertex last = to;
			Vertex previous_last = way[last];
			while (previous_last) {
				final_path.push_back(get_edge(previous_last, last));
				last = previous_last;
				previous_last = way.at(last);
			}
			final_path.push_back(get_edge(from, last));
			reverse(final_path.begin(), final_path.end());
			return final_path;
		}*/

		vector<Vertex> shortest_path(const Vertex& from, const Vertex& to) const {
			auto result = dijkstras_algorithm(from);
			const auto& prev = result.second;
			vector<Vertex> path;
			if (prev[to] == NULL) {
				return path;
			}
			path.push_back(to);
			for (auto v = prev[to]; v != from; v = prev[v]) {
				path.push_back(v);
			}
			path.push_back(from);
			reverse(path.begin(), path.end());
			return path;
		}

		Vertex find_the_most_remote_emergency_room() const {
			unordered_map<Vertex, Distance> result_table;
			for (const auto& vertex : _vertices) {
				vector<Edge<Vertex, Distance>> this_vertex_edges = edges(vertex);
				Distance this_vertex_avg_distance = 0;
				for (const auto& edge : this_vertex_edges) {
					this_vertex_avg_distance += edge.weight;
				}
				result_table[vertex] = (this_vertex_avg_distance * 1.0) / this_vertex_edges.size();
			}
			Vertex the_most_remote_emergency_room = -1;
			Distance result_distance = -1;
			for (const auto& [vertex, distance] : result_table) {
				if (distance > result_distance) {
					the_most_remote_emergency_room = vertex;
					result_distance = distance;
				}
			}
			return the_most_remote_emergency_room;
		}
	};
}