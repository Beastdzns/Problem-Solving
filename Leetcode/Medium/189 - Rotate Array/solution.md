# Solution 1:
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a;
        k=k%n;
        for(int i=n-1;i>n-1-k;i--){
            a.push_back(nums[i]);
        }
        reverse(a.begin(), a.end());

        for(int i=n-1;i>=k;i--){
            nums[i] = nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i] = a[i];
        }
    }
};
```