# Solution

## Approach 1 

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        int val = 0;
        for(int bit: nums){
            val = ((val << 1) + bit) % 5;
            if(val % 5 == 0) 
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
```