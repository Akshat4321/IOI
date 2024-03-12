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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct ufds{
    vector<int> par , siz;
    ufds(int n) : par(n) , siz(n,1){
        iota(all(par),0);
    }

    int findr(int u){
        if (par[u]==u) return u;
        return par[u] = findr(par[u]);
    }

    void unite(int u , int v){
        u = findr(u);
        v = findr(v);
        if (u==v) return;
        if (siz[u] < siz[v]) swap(u,v);
        siz[u] += siz[v];
        par[v] = u;
    }
};

struct val{
    int l , r , w;
    bool operator < (val const& temp) const {
        return w > temp.w;
    }
};

void Solve() {
    int n , m; cin>>n>>m;
    vi a(n+1);
    rep(i,1,n+1){
        cin>>a[i];
    }
    vector<val> nodes(m);
    for (int i = 0; i < m; ++i) {
        cin>>nodes[i].l>>nodes[i].r>>nodes[i].w;
    }
    sort(nodes.begin(), nodes.end());
    int ans = 1e9;
    int beg =  0;
    ufds dsu(n+1);
    rep(i, 1, n+1) {
        while (beg <= m-1 && dsu.findr(a[i]) != dsu.findr(i)) {
            ans = min(ans, nodes[beg].w);
            dsu.unite(nodes[beg].l, nodes[beg].r);
            beg++;
        }
    }

    if (beg==0){
        cout<<-1<<endl; //as we dont need any wormwhole
        return;
    }
    cout<<ans<<endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
#endif

    int t = 1;
 //   cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
