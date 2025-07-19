#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        set<int> sol;
        while(x > 0) {
            sol.insert(x % 10);
            x /= 10;
        }
        int ans = *sol.begin();
        cout << ans << endl;
    }
    return 0;
}