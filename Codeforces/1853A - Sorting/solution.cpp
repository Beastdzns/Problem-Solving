#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int> arr(n);
      int minGap = INT_MAX;
      bool isSorted = true;
      cin >> arr[0];
      for(int i=1;i<n;i++){
        cin >> arr[i];
        minGap = min(minGap, arr[i] - arr[i-1]);
      }
      
      for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1])
          isSorted = false;
      }
      
      if(isSorted)
        cout << minGap/2 + 1 << endl;
      else
        cout << 0 << endl;
        
    }
}