#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <map>
#include <set>

constexpr int V_SIZE {3};

using namespace std;

struct Vertex {
    char index[V_SIZE + 1] {};

    bool operator<(const Vertex& v2) const {
        int cmp = strcmp(index, v2.index);
        return cmp < 0;
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

    bool operator<(const Edge& edge2) const {
        if(start < edge2.start) return 1;
        if(edge2.start < start) return 0;

        return finish < edge2.finish;
    }

    friend ostream& operator<<(ostream& os, const Edge& edge) {
        os << edge.start << "-> " << edge.finish << endl;
        return os;
    }
};

using EdgeMap = map<Edge, int>;

ostream& operator<<(ostream& os, const EdgeMap& em) {
    for (const auto& pair : em) {
        cout << pair.second << " | " << pair.first << " ";
    }
    return os;
}

void init(set<Vertex>& vertex_set, EdgeMap& edge_weight_map) {
    int t_string;
    string filename = "data.txt";
    ifstream fin{filename};

    fin >> t_string;
    cout << t_string << endl;

    string word;
    for(int i = 0; i < t_string; i++) {
        fin >> word;
        string pvs = word.substr(0, V_SIZE);

        Vertex pv;
        pv.set(pvs);
        
        vertex_set.insert(pv);

        for(int j = 1; j <= word.size() - V_SIZE; j++) {
            string vs = word.substr(j, V_SIZE);

            Vertex v;
            v.set(vs);

            vertex_set.insert(v);

            Edge edge;
            edge.start.set(pvs);
            edge.finish.set(vs);

            edge_weight_map[edge]++;  // Увеличиваем количество вхождений пары 

            pvs = vs;
        }
        cout << endl;
    }

//    sort(vertex_list.begin(), vertex_list.end());
//    sort(edge_list.begin(), edge_list.end());
    

}

int main() {
    set<Vertex> vertex_set;
    EdgeMap edge_weight_map;

    init(vertex_set, edge_weight_map);

    cout << vertex_set.size() << endl;
    cout << edge_weight_map.size() << endl;
    cout << edge_weight_map;

    return 0;
}
