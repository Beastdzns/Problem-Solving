## Solution

### Approach 1 - Brute Force

Time Complexity : O(n^2)

```cpp
class Solution {
    using ll = long long;
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            ll product = 1;
            for(int j=i;j<n;j++){
                product *= nums[j];
                if(product < k){
                    cnt++;
                } else {
                    break;
                }
            }
        }
        return cnt;
    }
};
```

### Approach 2 - Sliding Window

Time Complexity : O(n)

```cpp
class Solution {
public:
    using ll = long long;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1)
            return 0;
    
        int l = 0, cnt = 0, r = 0;
        ll product = 1;
        while(r < n){
            product *= nums[r];
            while(product >= k){
                product /= nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
};
```