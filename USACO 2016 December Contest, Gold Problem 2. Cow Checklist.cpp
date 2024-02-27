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

int solve(pair<int,int> &a , pii &b){
    int dis1 = abs(a.f - b.f);
    int dis2 = abs(a.s-b.s);
    return (dis1*dis1) + (dis2*dis2);
}

void Solve() {
    int n , m; cin>>n>>m;
    vector<pair<int,int> > a(n+1) , b(m+1);
    rep(i,1,n+1){
        cin>>a[i].f>>a[i].s;
    }
    rep(i,1,m+1){
        cin>>b[i].f>>b[i].s;
    }
    vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (m+1,vector<int> (2,1e18)));
    //dp[i][j][k] = min dis for fj to visit first i h cows and j g cows given that fj is at k , k = 0 = h , k = 1 = g
    dp[1][0][0] = 0;
    for(int i = 2 ; i <= n ; i++){
        dp[i][0][0] = min(dp[i][0][0] , dp[i-1][0][0] +solve(a[i],a[i-1]));
    }
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j <=m ; j++){
            dp[i][j][0] = min( dp[i][j][0] , dp[i-1][j][0] + solve(a[i],a[i-1]));
            dp[i][j][0] = min(dp[i][j][0] , dp[i-1][j][1] + solve(a[i],b[j]));

            dp[i][j][1] = min(dp[i][j][1] , dp[i][j-1][1] + solve(b[j],b[j-1]));
            dp[i][j][1] = min(dp[i][j][1] , dp[i][j-1][0] + solve(b[j],a[i]));
        }
    }
    cout << dp[n][m][0]<<endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
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
