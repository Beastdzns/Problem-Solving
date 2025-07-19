#include<bits/stdc++.h>
using namespace std;
bool doAnnaWin(int a, int b, int c){
    if(c%2 == 0){
        if(b >= a)
            return false;
        else
            return true;
    }
    else {
        if(a >= b)
            return true;
        else 
            return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        bool ans = doAnnaWin(a, b, c);
        if(ans)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}