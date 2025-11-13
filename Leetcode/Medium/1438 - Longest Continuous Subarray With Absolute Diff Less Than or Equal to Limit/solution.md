# Solution

## Approach 1 - Using Sliding Window and Deque for managing min and max elements

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

### ❌ Why Variable Tracking Fails
- Using `minElem` and `maxElem` only:
  - Becomes **stale** when elements leave the window.
  - Resetting or incrementing `l` loses information or requires rescanning.
- Example: `nums = [10,1,2,4,7,2], limit = 5` → misses `[2,4,7,2]`.
- Complexity: O(n²) if recomputing min/max.

---

### Two Deques Solution
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

## Approach 2 - Using Sliding Window and Multiset

Time Complexity: O(n logn)
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int l = 0, res = 0;

        for (int r = 0; r < nums.size(); r++) {
            window.insert(nums[r]);

            // Shrink window if max - min > limit
            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[l]));
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
```


## Approach 3 - Using Sliding Window and Heap

Time Complexity: O(n logn)

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<int> maxHeap;            // max heap
        priority_queue<int, vector<int>, greater<int>> minHeap;  // min heap
        unordered_map<int,int> count;           // lazy removal
        int l = 0, res = 0;

        for (int r = 0; r < nums.size(); r++) {
            int val = nums[r];
            maxHeap.push(val);
            minHeap.push(val);
            count[val]++;

            // Shrink window
            while (!maxHeap.empty() && !minHeap.empty() &&
                   maxHeap.top() - minHeap.top() > limit) {
                
                int leftVal = nums[l];
                count[leftVal]--;
                l++;

                // Clean up heaps
                while (!maxHeap.empty() && count[maxHeap.top()] == 0)
                    maxHeap.pop();
                while (!minHeap.empty() && count[minHeap.top()] == 0)
                    minHeap.pop();
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
```