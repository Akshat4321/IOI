//https://usaco.org/index.php?page=viewproblem2&cpid=694

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

int dp[N][25][5];
char val[3] = {'H','P','S'};

bool check(char a , char b){
    if (a=='H' && b=='P') return true;
    if (a=='S' && b=='H') return true;
    if (a=='P' && b=='S') return true;
    return false;
}

void Solve() {
    int n , k; cin>>n>>k;
    vector<char> a(n+1);
    rep(i,1,n+1) cin>>a[i];
    int ans = 0;
//dp[i][k][c] = max value we get by playing till ith index and k moves are left and the currenct move is c
    for(int i = 1 ; i <= n ; i++){
        for(int j = k ; j >= 0 ; j--){
            for (int l = 0; l < 3; ++l) {
                for (int m = 0; m < 3; ++m) { //current move
                    if (l==m){
                        if (check(a[i],val[m])){
                            dp[i][j][m] = max(dp[i][j][m],dp[i-1][j][l] + 1);
                        }
                        else{
                            dp[i][j][m] = max(dp[i][j][m],dp[i-1][j][l]);
                        }
                    }
                    else{
                        if (check(a[i],val[m])){
                            dp[i][j][m] = max(dp[i][j][m],dp[i-1][j+1][l] + 1);
                        }
                        else{
                            dp[i][j][m] = max(dp[i-1][j+1][l],dp[i][j][m]);
                        }
                    }
                    ans = max(ans,dp[i][j][m]);
                }
            }

        }
    }
//    for (int i = 0; i < 3; ++i) {
//        ans = max(ans,dp[n][0][i]);
//    }
    cout<<ans<<endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
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
