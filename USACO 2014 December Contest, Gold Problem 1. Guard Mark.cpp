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

/*

*/

struct val{
    int ht , wt , st;
    //ht = hight
    //wt = weight
    //st = strength
};

void Solve() {
    int n , h ; cin>>n>>h;
    vector<val> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i].ht>>a[i].wt>>a[i].st;
    }
    vector<pii> dp(1<<(n+1));
    dp[0] = {0,INT_MAX};
    for (int i = 1; i < (1<<n); ++i) {
        dp[i] = {0,-1};
        for (int j = 0; j < n; ++j) {
            if (i&(1<<j)){
                int prev = i ^ (1<<j);
                dp[i].first+=a[j].ht;
                dp[i].second = max(dp[i].second , min(dp[prev].second - a[j].wt , a[j].st));
            }
        }
    }
    int ans = -1;
    for(int i = 1 ;i<(1<<n); i++){
        if (dp[i].first>=h) ans = max(ans,dp[i].second);
    }
    if(ans<0){
        cout<<"Mark is too tall"<<endl;
    } else{
        cout<<ans<<endl;
    }
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
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
