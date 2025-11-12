## Solution

### Approach 1

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(), 1);
        if(cnt > 0)
            return n-cnt;
        int len = INT_MAX;
        for(int i=0;i<n;i++){
            int x = nums[i];
            for(int j=i;j<n;j++){
                x = gcd(x, nums[j]);
                if(x == 1){
                    len = min(len, j-i+1);
                    break;
                }
            }
        }
        if(len == INT_MAX)
            return -1;

        return (len-1)+(n-1);
    }
};
```