#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    bool flag = false;
    int a,x,y;
    
    int bobPoint;
    int dist_bob_1;
    int dist_bob_2;
    
    cin >> a >> x >> y;
    int dist_alice_1 = abs(x-a);
    int dist_alice_2 = abs(y-a);
    
    //Case 1 
    bobPoint = x;
    dist_bob_1 = abs(x-bobPoint);
    dist_bob_2 = abs(y-bobPoint);
    
    if(dist_bob_1 < dist_alice_1 && dist_bob_2 < dist_alice_2)
      flag = true;
    
    if(flag == true){
      cout << "YES\n";
      continue;
    }
    
    //Case 2 
    bobPoint = y;
    dist_bob_1 = abs(x-bobPoint);
    dist_bob_2 = abs(y-bobPoint);
    
    if(dist_bob_1 < dist_alice_1 && dist_bob_2 < dist_alice_2)
      flag = true;
    
    if(flag == true){
      cout << "YES\n";
      continue;
    }
    
    //Case 3 
    bobPoint = (x+y)/2;
    dist_bob_1 = abs(x-bobPoint);
    dist_bob_2 = abs(y-bobPoint);
    
    if(dist_bob_1 < dist_alice_1 && dist_bob_2 < dist_alice_2)
      flag = true;
    
    if(flag == true){
      cout << "YES\n";
      continue;
    }
    if(flag == false)
    cout << "NO\n";
  }
  
  
  return 0;
  
}