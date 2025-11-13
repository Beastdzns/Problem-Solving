#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for(auto &x: arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    int i = 1;
    for(int x: arr){
        if(x != i){
            break;
        }
        i++;
    }
    cout << i << endl;
    return 0;
}