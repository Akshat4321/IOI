//AKSHAT IOI GOLD MEDALIST
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
//#define size size()
const int mod = 1000 * 1000 * 1000 + 7;
const int N = 100005;

bool cmp(const pair<int,int> &a , const pair<int,int> &b){
    return a.second<b.second;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);
//#endif
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

   int n ; cin>>n;
   vector<pair<int,int> > a;
    for (int i = 0; i < n; ++i) {
        int  x , y; cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(), a.end(),cmp);
    int l = 0 , r = n-1;
    int ans = -1;
    while (l<=r){
        ans = max(ans,a[l].second+a[r].second);
       int mn = min(a[l].first,a[r].first);
        if (l==r) mn/=2;
        a[l].first -=mn;
        a[r].first -=mn;
        if (a[l].first==0) l++;
        if (a[r].first==0) r--;
    }
    cout<< ans <<endl;

}