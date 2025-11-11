## Solution

### Approach 1 (Brute Force) - Time Complexity

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j] && abs(i-j) <=k)
                    return true;
            }
        }
        return false;
    }
};
```
### Approach 2 (Sliding Window)

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        if (n == 1)
            return false;

        int l = 0, r = 0;
        for (r; r <= min(n-1,k); r++) {
            freq[nums[r]]++;
            if (freq[nums[r]] >= 2)
                return true;
        }

        for (r; r < n; r++) {
            freq[nums[l]]--; l++;
            freq[nums[r]]++;
            if (freq[nums[r]] >= 2)
                return true;

            
        }
        return false;
    }
};
```