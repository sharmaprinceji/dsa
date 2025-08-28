#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void bfs(vector<int> adj[], queue<int> &q, vector<int> &indgress) {
    while (!q.empty()) {
        int node = q.front();
        q.pop();
       ans.push_back(node);

        for (auto it : adj[node]) {
            indgress[it]--;
            if (indgress[it] == 0) {    
                q.push(it);
            }
        }
    }
}   

void bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> indegree(V, 0);

    // Calculate indegree of each node
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    // Push all nodes with indegree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            visited[i] = 1;
        }
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            bfs(adj,q,indegree) ;
        }
    }
}

int main() {
    int V = 6;
    vector<int> adj[V];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "BFS Traversal: ";
    bfsOfGraph(V, adj);
    cout << endl;

    return 0;
}