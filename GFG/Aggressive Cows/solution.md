## Solution 

Approach 2: Using Binary Search
The canPlaceCows operation takes O(n) time complexity and it is performed log D times (where D is the maxDist). Thus the time complexity of this approach becomes:
O(n) * O(log D) = O(nlog D)

D = stalls.back() - stalls[0];

```cpp
class Solution {
  public:
    bool canPlaceCows(int k, int dist, vector<int> &stalls, int n){
        int prev = stalls[0];
        int cntCows = 1;
        for(int i=1;i<n;i++){
            if(stalls[i] - prev >= dist){
                cntCows++;
                prev = stalls[i];
            }   
        }
        return (cntCows >= k);
            
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        int result = 0;
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back() - stalls[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canPlaceCows(k, mid, stalls, n))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
```