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
        int year = stoi(s);
        int sq_root = sqrt(year);
        if(sq_root * sq_root == year)
            cout << "0" << " " << sq_root << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}