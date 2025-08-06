#include<bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    int points = 1;
    int score = 0;
    vector<vector<char>> goal(10, vector<char> (10, '.'));
    // Input
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        cin >> goal[i][j];
      }
    }
    
    // Operations
    int r1=0, r2=9, c1=0,c2=9;
    while(r1 < r2 && c1 < c2){
      
      for(int i=c1;i<=c2;i++){
        if(goal[r1][i] == 'X')
          score+= points;
      } r1++;
      
      for(int i=r1;i<=r2;i++){
        if(goal[i][c2] == 'X')
          score += points;
      }c2--;
      
      for(int i=c2;i>=c1;i--){
        if(goal[r2][i] == 'X')
          score += points;
      }r2--;
      
      for(int i=r2;i>=r1;i--){
        if(goal[i][c1] == 'X')
          score += points;
      } c1++;
      
      // Updation
      points++;
    }
    
    cout << score << endl;
  }
  return 0;
}