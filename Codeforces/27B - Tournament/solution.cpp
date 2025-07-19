#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  
  while(t--){
    int n,j,k;
    cin >> n >> j >> k;
    
    vector<int> a(n);
    int max_element = 0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(a[i] > max_element)
        max_element = a[i];
    }
    
    if(k >= 2){
      cout << "YES\n";
      continue;
    }

    if(a[j-1] == max_element)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}