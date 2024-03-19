#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF (int)1e18
#define endl '\n'
const int mod = 1000 * 1000 * 1000 + 7;
const int N = 100005;
#define f first
#define s second
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define rrep(i, a, b) for(int i = (a); i > (b); i--)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

//#ifndef ONLINE_JUDGE
//
//#include "template.cpp"
//
//#else
//#define debug(...)
//#define debugArr(...)
//#endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/*

*/
vector<pair<int,int> > adj[N];

void solve(vi &dis , int source){
    dis[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0,source);
    while (!pq.empty()){
        auto node = pq.top();
        pq.pop();
        for(auto &child : adj[node.second]){
            if (dis[node.second] + child.second < dis[child.first]){
                dis[child.first] = dis[node.second] + child.second;
                pq.push({dis[child.first], child.first});
            }
        }
    }
}


void Solve() {
    int n , m , k; cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        int u , v , t; cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    vi orgin(n+2,1e9);
    solve(orgin , n);
    for (int i = 0; i < k; ++i) {
        int u , v; cin>>u>>v;
        adj[n+1].push_back({u,orgin[u]-v});
    }
    vi newd(n+2,1e9);
    solve(newd,n+1);
    rep(i,1,n){
         cout<< (newd[i]<=orgin[i])<<endl;
    }
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
#endif

    int t = 1;
   // cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
