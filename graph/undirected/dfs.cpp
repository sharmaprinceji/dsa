#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void dfs(int node, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, visited, adj);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    dfs(0, visited, adj);
    return ans;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(4);
    adj[4].push_back(1);

    vector<int> result = dfsOfGraph(V, adj);
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
