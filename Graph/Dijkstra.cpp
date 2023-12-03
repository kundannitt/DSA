
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<ll> solve(vector<vector<pair<ll, ll>>>& graph, int from) {
    vector<ll> distance(graph.size(), 1e14);
    vector<bool> visited(graph.size(), false);
 
    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>
    > pq;
 
    pq.push({0LL, (ll) from});
    distance[from] = 0;
    
    while (!pq.empty()) {
        auto dist = pq.top().first;
        auto at = pq.top().second;
        pq.pop();
 
        visited[at] = true;
 
        if (distance[at] < dist) continue;
 
        for (auto node: graph[at]) {
            ll new_dist = dist + node.second;
            ll to = node.first;
 
            if (visited[to]) continue;
 
            if (new_dist < distance[to]) {
                distance[to] = new_dist;
                pq.push({new_dist, to});
            }
        }
    }
 
    return distance;
}
 
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n);
 
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        a -= 1; b -= 1;
 
        graph[a].push_back({b, c});
    }
 
    auto dist = solve(graph, 0);
    
    for (auto i: dist) cout << i << " ";
    cout << "\n";
}