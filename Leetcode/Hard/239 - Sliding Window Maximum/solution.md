# Solution

## Approach 1 - Using Multiset

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0, r=0, maxElem = INT_MIN;
        vector<int> res;
        multiset<int> maxNum;
        for(r=0;r<k;r++){
            maxNum.insert(nums[r]);
            maxElem = *maxNum.rbegin();
        }
        res.push_back(maxElem);
        for(r;r<n;r++){
            auto it = maxNum.find(nums[l]);
            maxNum.erase(it);
            maxNum.insert(nums[r]);
            maxElem = *maxNum.rbegin();
            res.push_back(maxElem);
            l++;
        }
        return res;
    }
};
```