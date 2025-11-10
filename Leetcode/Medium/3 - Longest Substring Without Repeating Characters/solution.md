## Solution
### Approach 1 (Using Sliding Window)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        unordered_map<char, int> idx;
        int count = 0;
        for (int r = 0; r < n; r++) {
            if (idx.find(s[r]) != idx.end() && idx[s[r]] >= l) {
                l = idx[s[r]] + 1;
            }
            idx[s[r]] = r;
            count = max(count, r - l + 1);
        }
        return count;
    }
};
```