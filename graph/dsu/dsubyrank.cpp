#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};  

int main() {
    DSU dsu(5);

    dsu.unionByRank(0, 1);
    dsu.unionByRank(1, 2);
    dsu.unionByRank(3, 4);

    cout << "Find(0): " << dsu.find(0) << endl; // Output: 0
    cout << "Find(1): " << dsu.find(1) << endl; // Output: 0
    cout << "Find(2): " << dsu.find(2) << endl; // Output: 0
    cout << "Find(3): " << dsu.find(3) << endl; // Output: 3
    cout << "Find(4): " << dsu.find(4) << endl; // Output: 3

    dsu.unionByRank(2, 3);

    cout << "After union of 2 and 3:" << endl;
    cout << "Find(0): " << dsu.find(0) << endl; // Output: 0
    cout << "Find(1): " << dsu.find(1) << endl; // Output: 0
    cout << "Find(2): " << dsu.find(2) << endl; // Output: 0
    cout << "Find(3): " << dsu.find(3) << endl; // Output: 0
    cout << "Find(4): " << dsu.find(4) << endl; // Output: 3

    return 0;
}