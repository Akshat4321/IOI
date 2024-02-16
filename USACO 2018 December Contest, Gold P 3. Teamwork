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

void Solve() {
    int n , k; cin>>n >>k;
    vi a(n+1);
    rep(i,1,n+1) cin>>a[i];
    vi dp(n+1);
    rep(i,1,n+1){
        int mx = a[i];
        for(int j = i-1 ; j>= 0 && (i-j)<=k ; j--){
            mx = max(mx,a[j+1]);
            dp[i] = max(dp[i] , dp[j] + (i-j)*mx);
        }
    }
    cout<< dp[n] << endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.outa", "w", stdout);
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
