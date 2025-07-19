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
    vector<int> arr(n);
    vector<int> minArr(n);
    vector<int> maxArr(n);
    
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }
    
    minArr[0] = arr[0];
    maxArr[n-1] = arr[n-1];
    
    for(int i=1;i<n;i++){
      minArr[i] = min(arr[i], minArr[i-1]);
    }
    
    for(int i=n-2;i>=0;i--){
      maxArr[i] = max(arr[i], maxArr[i+1]);
    }
    
    string ans = "";
    for(int i=0;i<n;i++){
        
      int left = (i == 0) ? INT_MAX : minArr[i-1];
      int right = (i == n-1) ? INT_MIN : maxArr[i+1];
      
      if(arr[i] < left || arr[i] > right)
        ans += '1';
      else
       ans += '0';
    }
    cout << ans << endl;
  }
  return 0;
}