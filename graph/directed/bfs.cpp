#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
void bfs(int start, vector<int> &visited, vector<int> adj[]) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    bfs(0, visited, adj);
    return ans;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    vector<int> result = bfsOfGraph(V, adj);
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}