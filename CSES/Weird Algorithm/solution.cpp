#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n;
  cin >> n;
  while(n != 1){
    cout << n << " ";
    if(n&1)
      n = (n*3) + 1;
    else
      n /= 2;
  }
  cout << n << "\n";
      
  return 0;
}