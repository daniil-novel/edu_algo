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

    return os << endl;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T*>& v) {
    for(const T *t : v) {
        os << *t;
    }

    return os << endl;
}

struct Vertex;
struct Command;
struct Component;

using Commandlist = vector<Command>;
using Vertexlist = vector<Vertex>;
using VertexPtrlist = vector<Vertex*>;
using Answerlist = vector<string>;

struct Component {
    VertexPtrlist vertex_ptrlist;

    Component(Vertex *v) : vertex_ptrlist{v} {}

    static Component *merge(Component *cmp1, Component *cmp2); 
};

struct Vertex {
    int index {0};
    Component *component; 

    Vertex(int ii) : index{ii}, component{new Component{this}} {
//         cout << "vertex: " << component->vertex_ptrlist << endl;
    }

    friend ostream& operator<<(ostream& os, const Vertex& v) {
        os << v.index << " | " << v.component << endl;
        return os;
    }

    static bool ask(const Vertex& u, const Vertex& v) {
        return u.component == v.component;
    }

    static void addEdge(Vertex& u, Vertex& v) {
        Component *cmpU = u.component;
        Component *cmpV = v.component;

        cout << cmpU->vertex_ptrlist;
        cout << cmpV->vertex_ptrlist;

        Component *cmp = Component::merge(cmpU, cmpV);

        cout << cmp->vertex_ptrlist;
        cout << "************************" << endl;
    }

    static void setVertexPtrlistComponent(VertexPtrlist& lst, Component *cmp) {
        for(auto *pv : lst) {
            pv->component = cmp;
        }
    }
};

Component *Component::merge(Component *cmp1, Component *cmp2) { 
    if(cmp1 == cmp2) return cmp1;

    auto& lst1 = cmp1->vertex_ptrlist;
    auto& lst2 = cmp2->vertex_ptrlist;
    auto *cmp_dst = cmp1;
    auto *cmp_src = cmp2;

    if(lst1.size() > lst2.size()) {
        cmp_dst = cmp1;
        cmp_src = cmp2;
    } else {
        cmp_dst = cmp2;
        cmp_src = cmp1;
    }

    auto& lst_src = cmp_src->vertex_ptrlist;
    auto& lst_dst = cmp_dst->vertex_ptrlist;

    lst_dst.insert(lst_dst.end(), lst_src.begin(), lst_src.end());

    Vertex::setVertexPtrlistComponent(lst_src, cmp_dst);

    delete cmp_src;

    return cmp_dst;
}


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
    string filename = "data.txt";
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
        Vertex& u = *vertex_ptrlist[cmd.ui];
        Vertex& v = *vertex_ptrlist[cmd.vi];

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
    cout << reversed_commandlist;

    VertexPtrlist vertex_ptrlist = vertexInit();
    Answerlist answerlist = execute(reversed_commandlist, vertex_ptrlist);

    cout << answerlist;

} 
