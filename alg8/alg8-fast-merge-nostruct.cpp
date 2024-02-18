#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int n_vertex;
int m_edge;
int k_operation;

struct Command {
    string name;
    int ui, vi;

    friend ostream& operator<<(ostream& os, const Command& cmd) {
        os << cmd.name << " " << cmd.ui << " -> " << cmd.vi << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Command& cmd) {
        return is >> cmd.name >> cmd.ui >> cmd.vi;
    }
};

using Commandlist = vector<Command>;
using Answerlist = vector<string>;

ostream& operator<<(ostream& os, const Answerlist& anslist) {
    for (const auto& ans : anslist) {
        os << ans;
    }
    return os;
}


namespace Vertex {
    vector<int> parent;
    vector<int> size;

    int findRoot(int v) {
        return v == parent[v] ? v : parent[v] = findRoot(parent[v]);
    }

    bool ask(int u, int v) {
        return findRoot(u) == findRoot(v);
    }

    void merge(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);

        if (u != v) {
            if (size[u] < size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

Commandlist commandlistInit(ifstream& fin) {
    Commandlist commands;
    for (int i = 0; i < k_operation; i++) {
        Command cmd;
        fin >> cmd;
        commands.push_back(cmd);
    }
    reverse(commands.begin(), commands.end());
    return commands;
}

void vertexlistInit() {
    Vertex::parent.assign(n_vertex + 1, 0);
    Vertex::size.assign(n_vertex + 1, 1);
    for (int i = 1; i <= n_vertex; ++i) {
        Vertex::parent[i] = i;
    }
}

void init(Commandlist& reversed_commandlist) {
    ifstream fin{"data1.txt"};
    fin >> n_vertex >> m_edge >> k_operation;
    for (int i = 0; i < m_edge; i++) {
        int ui, vi;
        fin >> ui >> vi;
    }
    reversed_commandlist = commandlistInit(fin);
}

Answerlist execute(Commandlist& reversed_commandlist) {
    Answerlist anslst;
    for (auto& cmd : reversed_commandlist) {
        if (cmd.name == "cut") {
            Vertex::merge(cmd.ui, cmd.vi);
        } else {
            anslst.push_back(Vertex::ask(cmd.ui, cmd.vi) ? "YES\n" : "NO\n");
        }
    }
    reverse(anslst.begin(), anslst.end());
    return anslst;
}

int main() {
    Commandlist reversed_commandlist;
    init(reversed_commandlist);
    vertexlistInit();
    Answerlist answerlist = execute(reversed_commandlist);
    cout << answerlist;
}

