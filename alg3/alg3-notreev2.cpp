#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    string filename = "alg3-data8.txt";
    ifstream fin{filename};

    int n = 0;
    fin >> n;
    cout << "n = " << n << endl;

    int *depth = new int[n + 1];

    depth[0] = 0;
    fill(depth + 1, depth + n + 1, -1);

    int max_depth = 0;
    int deepest_leaf_index = 0;
    for(int i = 1; i <= n; i++) {
        int pi;
        fin >> pi;
        depth[i] = depth[pi] + 1; 
        if(depth[i] > max_depth) {
            max_depth = depth[i];
            deepest_leaf_index = i;
        }
    }

    cout << deepest_leaf_index << " " << max_depth << endl;

    delete[] depth;
}
