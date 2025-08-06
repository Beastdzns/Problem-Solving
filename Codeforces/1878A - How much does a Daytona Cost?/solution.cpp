#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        bool kPres = false;
        for(int i: arr){
            cin >> i;
            if(i == k)
                kPres = true;
            
        }
        if(kPres)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}