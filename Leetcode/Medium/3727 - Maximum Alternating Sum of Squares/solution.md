## Solution 1

### Approach
Sort the array in absolute form(consider negative integers as positive as they will be squared) then square of the first half of the array will be subtracted and the square of the next half will be added to the final result.

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(),[](int a, int b){
            return abs(a) < abs(b);
        });
        long long ans = 0;
        // Even Positions (Minima)
        for(int i=0;i<n/2;i++){
            ans -= (nums[i] * nums[i]);
        }

        // Odd positions (Maxima)
        for(int i=n/2;i<n;i++){
            ans += (nums[i] * nums[i]);
        }
        
        return ans;
    }
};
```