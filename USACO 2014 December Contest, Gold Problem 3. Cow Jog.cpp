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

void Solve() {
    int n; cin>>n;
    int t; cin>>t;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        int pos , speed; cin>>pos>>speed;
        a[i] = - (pos + (speed*t));
    }
    vi sds; // shortes decreasing sequene

    for (int i = 0; i < n; ++i) {
        if (sds.empty() or a[i] >= sds.back()){
            sds.push_back(a[i]);
        }
        else{
            *upper_bound(sds.begin(), sds.end(),a[i]) = a[i];
        }
    }
    cout<<sds.size()<<endl;
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
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
