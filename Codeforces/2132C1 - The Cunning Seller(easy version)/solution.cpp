#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

#define debug(x) cerr << #x << " = " << (x) << "\n"

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print(vector<int> &x){
    int n = x.size();
    for(auto k: x){
        cout << k << " ";
    }
    cout << endl;
}

ll calc(ll x) {
    if(x == 1)  return 3;
    ll p = 0, tmp = 1;
    while(tmp < x) tmp *= 3, p++;
    return 3 * x + p * (x / 3);
}

void solve(vector<int> &base3) {
    ll n, cost = 0;
    cin >> n;
    
    while(n > 0){
        auto it = upper_bound(base3.begin(), base3.end(), n);
        it--;
        cost += calc(*it);
        n -= *it;
    }
    cout << cost << endl;
}

int main() {
    fast_io();
    ll curr = 1;
    int t = 1;
    cin >> t;
    vector<int> base3;
    base3.push_back(1);
    for(int i=1;i<=19;i++){
        curr *= 3;
        base3.push_back(curr);
    }
    while (t--) solve(base3);
}