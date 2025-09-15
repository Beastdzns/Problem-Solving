### Solution 1:

Topics: Array, String, Two Pointers

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        while(r < n) {
            if(nums[l] & 1 && nums[r]%2 == 0)
                swap(nums[l], nums[r]);
            else if(nums[l] & 1)
                r++;
            else {
                l++;
                r++;
            }
        }
        return nums;
    }
};
```