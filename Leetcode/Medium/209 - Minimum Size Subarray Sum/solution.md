## Solution

### Approach 1 (Brute Force) - Time Limit Exceeded
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cnt = INT_MAX;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum >= target)
                    cnt = min(cnt, j-i+1);
            }
        }
        return cnt == INT_MAX ? 0 : cnt;
    }
};
```

### Approach 2 (Sliding Window)

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cnt = INT_MAX;
        int l=0, r=0;
        int sum = 0;
        while(l <= r && r < n){
            sum += nums[r];
            while(sum >= target){
                sum -= nums[l];
                cnt = min(cnt, r-l+1);
                l++;
            }
            r++;
        }
        return cnt == INT_MAX ? 0 : cnt;
    }
};
```