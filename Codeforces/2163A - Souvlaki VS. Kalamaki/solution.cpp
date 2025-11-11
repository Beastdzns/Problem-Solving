#include <bits/stdc++.h>
using namespace std;

// Type aliases for convenience
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Macros for cleaner loops and code
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

// Debug macro (comment out before submission)
#define debug(x) cerr << #x << " = " << (x) << "\n"

// Fast I/O setup
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
// Main solve function for each test case

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());
    bool flag = true;
    for(int i=1;i+1<n;i+=2){
        if(arr[i] != arr[i+1])
            flag = false;
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    fast_io();
    int t = 1;
    // Uncomment the next line if multiple test cases exist:
    cin >> t;
    while (t--) solve();
}