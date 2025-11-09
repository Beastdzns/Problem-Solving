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

// Main solve function for each test case
void ans(string sol, int idx1, int idx2) {
    cout << sol << endl << idx1 << " " << idx2 << endl;
}

void ans(string sol){
    cout << sol << endl;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1;i<n;i++){
        if(s[i] < s[i-1]){
            ans("YES", i, i+1); 
            return;
        }
    }
    ans("NO");

}

int main() {
    fast_io();
    int t = 1;
    // Uncomment the next line if multiple test cases exist:
    // cin >> t;
    while (t--) solve();
}
