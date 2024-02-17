//https://usaco.org/index.php?page=viewproblem2&cpid=993
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

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vi adj[N];

/*looping order
 * ook i guess
its kinda intuitive

suppose this test case

3 3 1
0 10 20
1 2
2 3
3 1


n = 1, we reach city 2 in day 1 and all other dp[n][x] have -1 we skip them
then n = 2 , we reach city 3 in 2 day and .......
then n = 3 , we reach city 1 in day 3 , so dp[1][3] = 30 and ........

and now n = 4
so we break the for loop
and print 30 - 3 * 3

 but if we see we can still go to city 2 in day 4
and city 3 in day 5
and reach city 1 again in day 6
 
 and to do this 
we need to set days at 1st loop and city at 2nd loop
 * */


void Solve() {
    int n , m , c; cin>>n>>m>>c;
    vi val(n+1);
    rep(i,1,n+1) {
        cin >> val[i];
    }
    for (int i = 0; i < m; ++i) {
        int u , v; cin>>u>>v;
        adj[u].push_back(v);
    }

    //dp[i][j] = max money we earn by travelling tilll ith city in j days
    vector<vector<int> > dp(1005,vector<int> (1005,-1));
    dp[1][0] = 0;
    for(int i = 1; i <= 1000 ; i++){
        for(int j = 1 ; j <= n ; j++){
            if (dp[j][i-1]!=-1){
                for(auto v : adj[j]){
                    dp[v][i] = max(dp[v][i] , dp[j][i-1]+val[j]);
//                    cout<<'v'<<" = "<<v<<" "<<'j'<<" = "<<j<<"   "<<dp[v][j]<<endl;
//                    cout<<'i'<<" = "<<i<<" "<<"j-1"<<" = "<<j-1<<"   "<<dp[i][j-1]<<endl;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0 ;i <=1000 ; i++){
        ans = max(ans,dp[1][i] - (c*i*i));
    }
    cout << ans << endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
