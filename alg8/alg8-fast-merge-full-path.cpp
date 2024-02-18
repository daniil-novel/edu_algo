#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int n_vertex;
int m_edge;
int k_operation;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const T& t : v) {
        os << t;
    }

    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T*>& v) {
    for(const T *t : v) {
        os << *t;
    }

    return os;
}

struct Vertex;
struct Command;

using Commandlist = vector<Command>;
using Vertexlist = vector<Vertex>;
using VertexPtrlist = vector<Vertex*>;
using Answerlist = vector<string>;

struct Vertex {
    int index {0};
    Vertex *parent {this}; 
    int size {1};

    Vertex(int ii) : index{ii} {
//         cout << "vertex: " << component->vertex_ptrlist << endl;
    }

    friend ostream& operator<<(ostream& os, const Vertex* v) {
        os << v->index  << " (" << v->size << ")"<< " <- " << v->parent->index << endl;
        return os;
    }

    //NEW
    Vertex* findRoot_() {
        if(this == parent) {
            return this; 
        } else {
            return parent = parent->findRoot_();
        }
    }
    //NEW
    Vertex* findRoot() {
        Vertex *p;
        for(p = this; p != p->parent; p = p->parent);

        Vertex *root = p;
        for(p = this; p != p->parent; p = p->parent) {
            p->parent = root;
        }

        return root;
    }

    static bool ask(Vertex *u, Vertex *v) {
        return u->findRoot() == v->findRoot();
    }

    static void addEdge(Vertex *u, Vertex *v) {
//        cout << u;
//        cout << v;

        Vertex *root = merge(u, v);
//
//        cout << root;
//        cout << "************************" << endl;
    }

    static Vertex *merge(Vertex *u, Vertex *v) { 
        u = u->findRoot();
        v = v->findRoot();

        if(u == v) return u; 

        if(v->size > u->size) {
            swap(u, v);
        }

        v->parent = u;
        u->size += v->size;

        return u;
    }

};

struct Command {
    string name;
    int ui, vi; // индексы двух вершин, к которым относится команда

    friend ostream& operator<<(ostream& os, const Command& cmd) {
        os << cmd.name << " " << cmd.ui << " -> " << cmd.vi << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Command& cmd) {
        return is >> cmd.name >> cmd.ui >> cmd.vi;
    }
};

Commandlist commandInit() {
    string filename = "data6.txt";
    ifstream fin{filename};

    fin >> n_vertex >> m_edge >> k_operation;
    cout << n_vertex << " " << m_edge << " " << k_operation << endl;

    for(int i = 0; i < m_edge; i++) {
        int ui, vi;

        fin >> ui >> vi;
    }

    Commandlist commands;

    for(int i = 0; i < k_operation; i++) {
        Command cmd;
        fin >> cmd;

        commands.push_back(cmd);
    }

    reverse(commands.begin(), commands.end());

    return commands;
}

VertexPtrlist vertexInit() {
    VertexPtrlist vertex_ptrlist;

    for(int vi = 0; vi <= n_vertex; vi++) {
        vertex_ptrlist.push_back(new Vertex(vi));
    }

    return vertex_ptrlist;
}

Answerlist execute(Commandlist& reversed_commandlist, VertexPtrlist& vertex_ptrlist) {
    Answerlist anslst;

    for(auto cmd : reversed_commandlist) {
        Vertex *u = vertex_ptrlist[cmd.ui];
        Vertex *v = vertex_ptrlist[cmd.vi];

        if(cmd.name == "cut") {
            Vertex::addEdge(u, v);
        } else {
            anslst.push_back(Vertex::ask(u, v) ? "YES\n" : "NO\n");
        }
    }

    reverse(anslst.begin(), anslst.end());

    return anslst;
}

int main() {
    Commandlist reversed_commandlist = commandInit();
//    cout << reversed_commandlist;

    VertexPtrlist vertex_ptrlist = vertexInit();
    Answerlist answerlist = execute(reversed_commandlist, vertex_ptrlist);

//    cout << answerlist;

} 
