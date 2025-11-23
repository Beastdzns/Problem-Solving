# Solution

## Approach 1 - Greedy Approach

```cpp

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<int> rem1, rem2;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(nums[i] % 3 == 1)
                rem1.push_back(nums[i]);
            if(nums[i] % 3 == 2)
                rem2.push_back(nums[i]);
        }
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if(sum % 3 == 0)
            return sum;

        int finalRem = sum % 3;
        int result = 0;
        if(finalRem == 2){
            int option1 = rem1.size() >= 2 ? rem1[0] + rem1[1] : INT_MAX;
            int option2 = rem2.size() >= 1 ? rem2[0] : INT_MAX;
            result = max(result, sum - min(option1, option2));
        }
        if(finalRem == 1){
            int option1 = rem2.size() >= 2 ? rem2[0] + rem2[1] : INT_MAX;
            int option2 = rem1.size() >= 1 ? rem1[0] : INT_MAX;
            result = max(result, sum - min(option1, option2));
        }
        return result;
    }
};

```