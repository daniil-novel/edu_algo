#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int index; // Индекс узла
    int depth;
    Node *parent;
};

struct Tree {
    int size;
    int max_depth {};
    Node *root;
    Node *deepest_leaf {};
    Node *nodes;

    Tree(int s) : size{s}, nodes{new Node[s] {}}, root{nodes} {}
    ~Tree() {
        delete[] nodes;
    }
};


ostream& operator<<(ostream& os, const Node* node) {
    os << "Глубина узла " << node->depth << " индекса " << node->index << endl;
    return os;
}

int main() {
    string filename = "alg3-data8.txt";
    ifstream fin{filename};

    int n = 0;
    fin >> n;
    cout << "n = " << n << endl;

    Tree tr{n + 1};

    for(int i = 1; i <= n; i++) {
        Node *nd = &tr.nodes[i];

        nd->index = i;

        int pi;
        fin >> pi;
        Node *pnd = &tr.nodes[pi];

        nd->parent = pnd;
        nd->depth = pnd->depth + 1;

        if(nd->depth > tr.max_depth) {
            tr.max_depth = nd->depth;
            tr.deepest_leaf = nd;
        }
    }

    cout << tr.deepest_leaf->index << " ";
    cout << tr.max_depth;
}
