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

## ❌ Why Variable Tracking Fails
- Using `minElem` and `maxElem` only:
  - Becomes **stale** when elements leave the window.
  - Resetting or incrementing `l` loses information or requires rescanning.
- Example: `nums = [10,1,2,4,7,2], limit = 5` → misses `[2,4,7,2]`.
- Complexity: O(n²) if recomputing min/max.

---

## Two Deques Solution
Use **two monotonic deques**:
1. `maxDeque` — decreasing order, front = current max.
2. `minDeque` — increasing order, front = current min.

**Steps:**
1. Add `nums[r]`:
   - Pop smaller (maxDeque) / larger (minDeque) from back.
   - Push `nums[r]` to back.
2. If `maxDeque.front() - minDeque.front() > limit`:
   - Shrink window: `l++`.
   - Remove leaving elements from deque fronts.

**Benefits:**
- Always up-to-date min/max in O(1).
- Efficient window shrinking/expanding.
- Overall O(n) time complexity.

---