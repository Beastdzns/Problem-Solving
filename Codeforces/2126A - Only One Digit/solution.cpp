#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char ans = '9';
        for(const auto& x: s){
            ans = min(ans, x);
        }
        cout << ans << endl;
    }
    return 0;
}