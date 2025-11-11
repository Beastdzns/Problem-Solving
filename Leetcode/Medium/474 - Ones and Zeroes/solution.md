## Solution

### Approach 1 - Dynamic Programming (without memoization)

Time Complexity : 0(2^k) where k is the number of strings

```cpp
class Solution {
public:
    int solve(vector<pair<int, int>> &arr, int m, int n, int i){
        if(i >= arr.size() || (m == 0 && n == 0))
            return 0;
        int take = 0;
        if(arr[i].first <= m && arr[i].second <= n)
            take = 1 + solve(arr, m - arr[i].first, n - arr[i].second, i+1);
        int skip = solve(arr, m, n, i+1);
        return max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<pair<int, int>> arr;
        for(string str: strs){
            int zeros = 0;
            int ones = 0;
            for(int i=0;i<str.size();i++){
                if(str[i] == '0')
                    zeros++;
                else
                    ones++;
            }
            arr.push_back({zeros, ones});
        }
        return solve(arr, m, n, 0);
    }
};
```

### Approach 2 - Dynamic Programming (with memoization)

Time Complexity : 0(k x m x n) where k is the number of strings

```cpp
class Solution {
public:
    int t[101][101][601];
    int solve(vector<pair<int, int>> &arr, int m, int n, int i){
        if(i >= arr.size() || (m == 0 && n == 0))
            return 0;

        if(t[m][n][i] != -1)
            return t[m][n][i];

        int take = 0;
        if(arr[i].first <= m && arr[i].second <= n)
            take = 1 + solve(arr, m - arr[i].first, n - arr[i].second, i+1);
        int skip = solve(arr, m, n, i+1);
        return t[m][n][i] = max(skip, take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<pair<int, int>> arr;
        for(string str: strs){
            int zeros = 0;
            int ones = 0;
            for(int i=0;i<str.size();i++){
                if(str[i] == '0')
                    zeros++;
                else
                    ones++;
            }
            arr.push_back({zeros, ones});
        }
        memset(t, -1, sizeof(t));
        return solve(arr, m, n, 0);
    }
};
```