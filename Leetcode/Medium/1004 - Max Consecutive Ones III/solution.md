## Solution
### Approach 1 (Using Sliding Window)

``` cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r = 0, n = nums.size();
        int l = 0;
        int count = 0;
        int tempK = k;
        while(l <= r && r < n){
            if(nums[r] == 0)
                tempK--;
            if(tempK == -1){
                l++;
                r = l;
                tempK = k;
                continue;
            }
            count = max(count, r-l+1);
            r++;
            
        }
        return count;
    }
};
```

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, zeroCount = 0, maxLen = -1;
        for(int r = 0;r<n;r++){
            if(nums[r] == 0){
                zeroCount++;
            }
            while(zeroCount > k){
                if(nums[l] == 0)
                    zeroCount--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
```