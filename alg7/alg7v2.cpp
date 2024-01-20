#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

constexpr int V_SIZE {3}; 

using namespace std;

struct Vertex {
    char index[V_SIZE + 1] {};

    bool operator<(Vertex& v2) {
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

    bool operator<(Edge& edge2) {
        if(start < edge2.start) return 1;
        if(edge2.start < start) return 0;

        return finish < edge2.finish;
    }

    friend ostream& operator<<(ostream& os, const Edge& edge) {
        os << edge.start << "-> " << edge.finish << endl;
        return os;
    }
};

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
        for(int j = 1; j <= word.size() - V_SIZE - 1; j++) {
            string vs = word.substr(j + 1, V_SIZE);

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

    sort(vertex_list.begin(), vertex_list.end());
    sort(edge_list.begin(), edge_list.end());
    
//    cout << vertex_list << endl;
    cout << edge_list << endl;
}

int uniqueVertexCount(auto& vertex_list) {
    int k = 0;
    Vertex pv;
    for(auto& v : vertex_list) {
//        cout << v << endl;
        if(!(pv == v)) {
            k++;
        }

        pv = v;
    }

    return k;
}

int main() {
    
    vector<Vertex> vertex_list;
    vector<Edge> edge_list;

    init(vertex_list, edge_list);

    cout << uniqueVertexCount(vertex_list) << endl;

}
