#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int lcnt=0, rcnt=0;
    //Case 1 
    if((a[r] - a[l]) % 2 == 0)
      cout << 0 << endl;
    
    //Case 2 - Odd - Even
    else if (a[l] %2 == 1){
      while(a[l] %2 == 1){
        if(a[l] %2 == 0)
          break;
        lcnt++;
        l++;
      }
      
      while(a[r] %2 == 0){
        if(a[r] %2 == 1)
          break;
        rcnt++;
        r--;
      }
      
      cout << min(lcnt, rcnt) << endl;
    }
    
    //Case 3 Even - Odd 
    else if(a[l] %2 == 0){
      while(a[l] %2 == 0){
        if(a[l] %2 == 1)
          break;
        lcnt++;
        l++;
      }
      
      while(a[r] %2 == 1){
        if(a[r] % 2 == 0)
          break;
        rcnt++;
        r--;
      }
      cout << min(lcnt, rcnt) << endl;
    }
  }
  return 0;
}