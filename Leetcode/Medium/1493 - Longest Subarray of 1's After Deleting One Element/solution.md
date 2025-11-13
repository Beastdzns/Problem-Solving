# Solution

## Approach 1 - Brute Force

Time Complexity: O(n^2)

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            int best = 0;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                if (nums[j] == 1) {
                    curr++;
                } else {
                    best = max(best, curr);
                    curr = 0;
                }
            }
            best = max(best, curr);
            maxLen = max(maxLen, best);
        }
        return maxLen == n ? n - 1 : maxLen;
    }
};
```

## Approach 2 - Sliding Window

Time Complexity: O(n)

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0, maxLen = 0, zeroCount = 0;
        for(int r=0;r<n;r++){
            if(nums[r] == 0)
                zeroCount++;
            while(zeroCount > 1){
                if(nums[l] == 0)
                    zeroCount--;
                l++;
            }
            maxLen = max(maxLen, r-l);
        }
        return maxLen;
    }
};
```
## Approach 3 - Sliding Window Optimized

Time Complexity: O(n)

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0, maxLen = 0, lastZeroIndex = -1;
        for(int r=0;r<n;r++){
            if(nums[r] == 0){
                l = lastZeroIndex + 1;
                lastZeroIndex = r;
            }            
            maxLen = max(maxLen, r-l);
        }
        return maxLen;
    }
};
```
