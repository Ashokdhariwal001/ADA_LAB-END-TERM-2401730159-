#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii; // (distance, node)

void dijkstra(vector<vector<pii>>& adj, int src, int V){

    vector<int> dist(V, INT_MAX);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        for(auto &edge : adj[u]){

            int w = edge.first;
            int v = edge.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source (" << src << ")\n";
    cout << "---------------------------------\n";

    for(int i=0;i<V;i++){
        cout << i << "\t" << dist[i] << endl;
    }
}

int main(){

    int V = 5;
    vector<vector<pii>> adj(V);

    // (weight, vertex)
    adj[0].push_back({10, 1});
    adj[0].push_back({3, 4});

    adj[1].push_back({2, 2});
    adj[1].push_back({4, 4});

    adj[2].push_back({9, 3});

    adj[3].push_back({7, 2});

    adj[4].push_back({8, 1});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 3});

    dijkstra(adj, 0, V);

    return 0;
}
