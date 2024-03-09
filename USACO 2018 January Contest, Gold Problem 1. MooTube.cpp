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

struct Edge{
    int l , r , val;
};

bool cmp( const Edge &a ,const Edge &b){
    return a.val > b.val;
}

struct Query{
    int rev , vid , idx;
};

bool cmp2(const Query &a , const Query &b){
    return a.rev > b .rev;
}

struct UFDS{
    vi siz , par;
    UFDS(int n) : siz(n,1) , par(n){
        iota(par.begin(), par.end(),0);
    }
    int findr(int u){
        if (u==par[u]) return u;
        return par[u] = findr(par[u]);
    }
    void unite(int u , int v){
        u = findr(u);
        v = findr(v);
        if(u==v) return;
        if (siz[u]<siz[v]) swap(u,v);
        siz[u] += siz[v];
        par[v] = u;
    }
};

void Solve() {
    int n = 0, q = 0; cin>>n>>q;
    int temp = n;
    vector<Edge> edge(n-1);
    for (int i = 0; i < n - 1; ++i) {
        cin>>edge[i].l>>edge[i].r>>edge[i].val;
    }
    sort(edge.begin(), edge.end(),cmp);

    vector<Query> query(q);
    for (int i = 0; i < q; ++i) {
        cin>>query[i].rev>>query[i].vid;
        query[i].idx = i;
    }
    sort(query.begin(), query.end(),cmp2);

    UFDS dsu(n+1);
    vi ans(q);

    int j = 0;
    for (int i = 0; i < q; ++i) {
        while (j<n-1 && edge[j].val >= query[i].rev){
            dsu.unite(edge[j].l ,edge[j].r);
            j++;
        }
        ans[query[i].idx] = dsu.siz[dsu.findr(query[i].vid)];
    }

    for (int i = 0; i < q; ++i) {
        cout<<ans[i]-1<<endl;
    }

}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
#endif

//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//#endif


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
