## Solution

### Approach 1 (Brute Force)
This still works as the contraint is n <=500. In this approach, all subarrays are considered and checked whether they are consecutive. If yes then the last element of the subarray is pushed to the result, if no then -1 is pushed.

Time Complexity: O(n * k)

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n-k+1;i++){
            bool flag = true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j] != nums[j-1] + 1){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(nums[i+k-1]);
            else
                res.push_back(-1);
        }
        return res;
    }
};

```

### Approach 2 (Using Auxillary Array)
In this approach an auxillary array F has been used that tracks the consecutive elements in the sequence. This approach does not requires us to keep track of all subarrays and just tracks the series of consecutive elements, thus making it easier to append the max element to the answer.

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>f(n,1);
        vector<int> res;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1] + 1)
                f[i] = f[i-1] + 1;
        }
        for(int i=k-1;i<n;i++){
            if(f[i] >= k)
                res.push_back(nums[i]);
            else
                res.push_back(-1);
        }
        return res;
    }
};

```

### Approach 3 (Sliding Window)
In this approach we solve this question using a fixed sliding window where we start with the first window of size k and then move forward checking the new element with the previous element. The count variable is necessary to determine the number of consecutive elements thus helping us determine the number of consecutive subarrays.

``` cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int count = 1;
        int i = 1;
        for(i=1;i<k;i++){
            if(nums[i] == nums[i-1] + 1)   
                count++;
            else
                count = 1;
        }
        if(count >=k)
            res.push_back(nums[k-1]);
        else
            res.push_back(-1);
        while(i < n){
            if(nums[i] == nums[i-1] + 1)
                count++;
            else
                count = 1;
            
            if(count >=k)
                res.push_back(nums[i]);
            else
                res.push_back(-1);
        i++;
        }
        return res;
    }
};
```

### Approach 4 (using Monotonic Deque)

```cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();

        deque<int> deq; // Monotonic Deque

        for(int i=0;i<n;i++){
            if(deq.size() == k)
                deq.pop_front();
            
            if(!deq.empty() && deq.back() != nums[i] - 1)
                deq.clear();
            
            deq.push_back(nums[i]);

            if(i >= k-1){
                if(deq.size() >= k)
                    res.push_back(nums[i]);
                else
                    res.push_back(-1);
            }
        }
        return res;
    }
};
```