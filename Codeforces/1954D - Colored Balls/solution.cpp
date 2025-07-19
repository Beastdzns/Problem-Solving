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
    vector<int> balls(n);
    for(int i=0;i<n;i++){
      cin >> balls[i];
    }
    
    int largest = balls[n-1];
    int second_largest = balls[n-2];
    
    long long totalCount = 0;
    
    for(int i=0;i<n;i++){
      int ball_1 = 2 * balls[i];
      
      int ball_2 = (i == n-1 ? second_largest:largest);
      
      int total = max(ball_1,ball_2);
      int X = total - balls[i];
      
      int left=0;
      int right = i-1;
      while(left < right){
        int sum = balls[left] + balls[right];
        if(sum > X){
          totalCount += (right-left);
          right--;
        } else
          left++;
        }
      }
      cout << totalCount << "\n";
    }
  return 0;
}