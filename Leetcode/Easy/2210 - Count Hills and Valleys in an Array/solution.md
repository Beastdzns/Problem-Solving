```cpp

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> newArr;
        int hillValley = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] != nums[i+1])
                newArr.push_back(nums[i]);
        }
        newArr.push_back(nums[n-1]);

        for(int i=1;i<newArr.size()-1;i++){
            int m = newArr[i-1];
            int n = newArr[i+1];
            if(newArr[i] > m && newArr[i] > n)
                hillValley++;
            else if(newArr[i] < m && newArr[i] < n)
                hillValley++;
        }
        return hillValley;
    }
};

```