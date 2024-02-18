#include <iostream>
#include <vector>
#include <list>
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
using VertexPtrllist = list<Vertex*>;
using Answerlist = vector<string>;

struct Vertex {
    int index {0};
    Vertex *parent {this}; 
    VertexPtrllist children {};
    int size {1};
    int depth {1};
    static Vertex* v_max_depth; //NEW
    static int max_depth;

    Vertex(int ii) : index{ii} {
//         cout << "vertex: " << component->vertex_ptrlist << endl;
    }

    friend ostream& operator<<(ostream& os, const Vertex* v) {
        os << v->index 
           << "{size: " << v->size << ", depth: " << v->depth << "}"
           << " <- " << v->parent->index
           << "{size: " << v->parent->size << ", depth: " << v->parent->depth << "}"
           << endl;
        return os;
    }

    //NEW
    void printTree(int level = 0) {
        Vertex *vertex = this;

        cout << string(level, '\t');
        cout << vertex;

        for(Vertex* child : vertex->children) {
            child->printTree(level + 1);
        }
    }

    void attach(Vertex *v) {
        children.push_back(v);

        v->parent = this;

        for(Vertex *p = v; p != p->parent; p = p->parent) {
            Vertex *parent = p->parent;
            parent->size += v->size;

            parent->depth = max(parent->depth, p->depth + 1);

            //NEW
            if(parent->depth > max_depth) {
                max_depth = parent->depth;
                v_max_depth = parent;
                v_max_depth->printTree();
            }
        }
    }

    void detach(Vertex *v) {
        int child_count = children.size();
        children.remove(v);
        if(child_count == children.size()) return;

        for(Vertex *p = v; p != p->parent; p = p->parent) {
            Vertex *parent = p->parent;
            parent->size -= v->size;
            
            if(parent->children.empty()) { 
                parent->depth = 1;
            } else {
                parent->depth = maxDepth(parent->children) + 1;
            }

        }

        v->parent = v;
    }

    static int maxDepth(VertexPtrllist& v_ptrlist) {
        int max_child_depth = 0;
        for(auto *p : v_ptrlist) {
            if(p->depth > max_child_depth) {
                max_child_depth = p->depth;
            }
        }

        return max_child_depth;
    }

    static int maxDepth_(VertexPtrllist& v_ptrlist) {
        auto cmp = [](Vertex *u, Vertex *v) {
            return u->depth < v->depth;
        };
        
        auto max_child_it = max_element(v_ptrlist.begin(), v_ptrlist.end(), cmp);
        
        int max_child_depth = 0;
        if(max_child_it != v_ptrlist.end()) {
            max_child_depth = (*max_child_it)->depth;
        }

        return max_child_depth;
    }

    static double meanDepth(VertexPtrlist& v_ptrlist) {
        double s = 0;
        for(auto *v : v_ptrlist) {
            s += v->depth;
        }

        return s / v_ptrlist.size();
    }

    Vertex *findRoot() {
        Vertex *p;
        for(p = this; p != p->parent; p = p->parent) {
            Vertex *parent = p->parent;

            parent->detach(p);
            parent->parent->attach(p);
        }
        return p;
    }

    static bool ask(Vertex *u, Vertex *v) {
        return u->findRoot() == v->findRoot();
    }

    static void addEdge(Vertex *u, Vertex *v) {
//        cout << u;
//        cout << v;

        Vertex *root = merge(u, v);

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

        u->attach(v);

        return u;
    }
};
/*конец структуры Vertex*/

//NEW
Vertex* Vertex::v_max_depth = nullptr;

int Vertex::max_depth {1};

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

    cout << Vertex::max_depth << endl;
    cout << Vertex::meanDepth(vertex_ptrlist) << endl;
    
    //NEW
//    Vertex::v_max_depth->printTree();

} 
