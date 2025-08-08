#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int> arr(n);
      
      for(int i=0;i<n;i++){
        cin >> arr[i];
      }
      
      int oddCount = 0;;
      for(int i=0;i<n;i++){
        if(arr[i] & 1)
          oddCount++;
      }
      
      if(oddCount & 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
    return 0;
}