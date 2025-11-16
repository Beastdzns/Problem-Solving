# Solution

## Approach 1 - Using Brute Force (TLE)

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(temperatures[j] > temperatures[i]){
                    res.push_back(j-i);
                    break;
                }
                if(j == n-1)
                    res.push_back(0);
            }
        }
        return res;
    }
};
```

## Approach 2 - Using Stack

### 1.
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n , 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
```

### 2.
```cpp
int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if(st.empty())
                res[i] = 0;
            else
                res[i] = st.top() - i;

            st.push(i);
        }
        return res;
```