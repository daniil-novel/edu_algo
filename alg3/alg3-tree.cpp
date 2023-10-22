#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node {
    int index; // Индекс узла
    int depth;
    vector<Node*> children; // Вектор детей узла
    Node *parent;
    
};

ostream& operator<<(ostream& os, const Node* node) {
    os << "Глубина узла " << node->depth << " индекса " << node->index << endl;
    for (const Node* child : node->children) {
        os << "   Дочерний узел: " << child->depth << " индекса " << child->index << endl;
    }
    return os;
}

int main() {
    string filename = "alg3-data.txt";
    ifstream fin{filename};

    int n = 0;
    fin >> n;
    cout << "n = " << n << endl;

    Node *tree = new Node[n + 1] {};
    Node *root = tree; 

    int max_depth = 0;
    Node *deepest_leaf = nullptr;

    for(int i = 1; i <= n; i++) {
        Node *nd = &tree[i];

        nd->index = i;

        int pi;
        fin >> pi;
        Node *pnd = &tree[pi];

        nd->parent = pnd;
        pnd->children.push_back(nd);
        nd->depth = pnd->depth + 1;

        if(nd->depth > max_depth) {
            max_depth = nd->depth;
            deepest_leaf = nd;
        }
    }
    delete[] tree;
    cout << deepest_leaf->index;
}
