## Solution

### Approach 1 - Using Sliding Window and Deque for managing min and max elements

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), l = 0;
        int cnt = 0;
        deque<int> minDq, maxDq;
        for(int r=0;r<n;r++){
            int curr = nums[r];
            while(!maxDq.empty() && curr > maxDq.back())
                maxDq.pop_back();
            maxDq.push_back(curr);

            while(!minDq.empty() && curr < minDq.back())
                minDq.pop_back();
            minDq.push_back(curr);

            while(!minDq.empty() && !maxDq.empty() && maxDq.front() - minDq.front() > limit){
                if(nums[l] == maxDq.front()) maxDq.pop_front();
                if(nums[l] == minDq.front()) minDq.pop_front();
                ++l;
            }
            cnt = max(cnt, r - l + 1);
        }
        return cnt;
    }
};
```