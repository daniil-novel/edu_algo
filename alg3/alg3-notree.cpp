#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;


int findDepth(int i, int *parent_index, int *depth) {
    stack<int> path;
    path.push(i);

    while(1) {
        int pi = parent_index[i];
//        cout << i << " " << pi << " " << depth[pi] << endl;
        
        if(depth[pi] != -1) {
            depth[i] = depth[pi] + 1;
            path.pop();
        } else {
            path.push(pi); 
        }

        if(path.empty()) {
            return depth[i];
        }

        i = path.top();
    }
}

int main() {
    string filename = "alg3-data8.txt";
    ifstream fin{filename};

    int n = 0;
    fin >> n;
    cout << "n = " << n << endl;

    int *depth = new int[n + 1];
    int *parent_index = new int[n + 1];

    depth[0] = 0;
    for(int i = 1; i <= n; i++) {
        fin >> parent_index[i];
        depth[i] = -1;
        //        cout << "parent_index[" << i << "] = " << parent_index[i] << " | " << i << endl;
    }

    int countParent = 0;
    int max_depth = 0;
    int deepest_leaf_index = 0;
    for(int j = n; j >= 0; j--) {
        int d = findDepth(j, parent_index, depth);
        if(d > max_depth) {
            max_depth = d;
            deepest_leaf_index = j;
        }
    }

    cout << deepest_leaf_index << " " << max_depth << endl;

    delete[] parent_index;
    delete[] depth;
}
