#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>


constexpr int V_SIZE {3}; 

using namespace std;

struct Vertex {
    char index[V_SIZE + 1] {};

    bool operator<(const Vertex& v2) const {
        int cmp = strcmp(index, v2.index);
        return cmp < 0;
    }

    bool operator==(Vertex& v2) {
        int cmp = strcmp(index, v2.index);
        return cmp == 0;
    }

    void set(string& vs) {
        copy(vs.begin(), vs.end(), index);
    }

    friend ostream& operator<<(ostream& os, const Vertex& v) {
        os << v.index << " ";
        return os;
    }

};

struct Edge {
    Vertex start {};
    Vertex finish {};

    int weight {1};

    bool operator<(const Edge& edge2) const {
        if(start < edge2.start) return 1;
        if(edge2.start < start) return 0;

        return finish < edge2.finish;
    }

    bool operator==(Edge& edge2) {
        return start == edge2.start && finish == edge2.finish;
    }

    friend ostream& operator<<(ostream& os, const Edge& edge) {
        os << edge.start << "-> " << edge.finish << ": " << edge.weight << endl;
        return os;
    }
};

using EdgeMap = map<Edge, int>;

ostream& operator<<(ostream& os, const EdgeMap& m) {
    for(const auto& pair : m) {
        const Edge& e = pair.first;
        const int& weight = pair.second;
        os << e.start << e.finish << weight << endl;
    }

    return os;
}


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const T& t : v) {
        os << t;
    }

    return os << endl;
}

void init(vector<Vertex>& vertex_list, vector<Edge>& edge_list) {
    int t_string;

    string filename = "data.txt";
    ifstream fin{filename};

    fin >> t_string;    
    cout << t_string << endl;

    string word;
    for(int i = 0; i < t_string; i++) {
        fin >> word;
        string pvs = word.substr(0, V_SIZE);
        for(int j = 1; j <= word.size() - V_SIZE; j++) {
            string vs = word.substr(j, V_SIZE);

            //            cout << pvs << " -> " << vs << endl;

            Vertex v;
            v.set(vs);

            vertex_list.push_back(v);

            Edge edge;

            edge.start.set(pvs);
            edge.finish.set(vs);

            //            cout << edge.start << " -> " << edge.finish << endl;

            edge_list.push_back(edge);
            pvs = vs;
        }
        cout << endl;

    }

    //    sort(vertex_list.begin(), vertex_list.end());
    //    sort(edge_list.begin(), edge_list.end());
    
//    cout << vertex_list << endl;
//    cout << edge_list << endl;
}

int uniqueVertexCount(vector<Vertex>& vertex_list) {
    int k = 0;
    Vertex pv;
    for(auto& v : vertex_list) {
        if(!(pv == v)) {
            k++;
        }

        pv = v;
    }

    return k;
}

int uniqueSetVertexCount(vector<Vertex>& vertex_list) {
    set<Vertex> vertex_set {vertex_list.begin(), vertex_list.end()};
    return vertex_set.size();
}

int uniqueStdVertexCount(vector<Vertex>& vertex_list) {
    auto unique_end = unique(vertex_list.begin(), vertex_list.end());
    
    return unique_end - vertex_list.begin();
}

void uniqueEdgeCounter(vector<Edge>& edge_list, vector<Edge>& unique_edge_list) {
    Edge pe;
    for(auto& e : edge_list) {
        if(!(pe == e)) {
            unique_edge_list.push_back(e);
        } else {
            unique_edge_list.back().weight++;
        }

        pe = e;
    }
}

EdgeMap uniqueMapEdgeCounter(vector<Edge>& edge_list) {
    EdgeMap edge_map;
    for(auto& e : edge_list) {
        edge_map[e]++; 
    }

    return edge_map;
}

int main() {
    vector<Vertex> vertex_list;
    vector<Edge> edge_list;
    vector<Edge> unique_edge_list;

    init(vertex_list, edge_list);

    cout << uniqueSetVertexCount(vertex_list) << endl;

    const EdgeMap& edge_map = uniqueMapEdgeCounter(edge_list);

    cout << edge_map.size() << endl;
    cout << edge_map;
}
