#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF (int)1e18
#define endl '\n'
const int mod = 1000 * 1000 * 1000 + 7;
const int N = 100005;
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
//idea - we are given final array and also given from where they were moved
//so we will move our array to the postion from which they come
void Solve() {
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    vector<string> ans1(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j]-1==i){
                ans1[j] = s[i];
            }
        }
    }
    vector<string> ans2(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j]-1==i){
                ans2[j] = ans1[i];
            }
        }
    }
    vector<string> ans3(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j]-1==i){
                ans3[j] = ans2[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout<<ans3[i]<<endl;
    }

}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
#endif

    int t = 1;
  //  cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
