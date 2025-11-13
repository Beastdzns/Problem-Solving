## Solution
### Approach 1 (Brute Force) 

Time Complexity: O(n^3)

```cpp
int characterReplacement(string s, int k) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> count(26, 0);
            for (int p = i; p <= j; p++) {
                count[s[p] - 'A']++;
            }
            int maxCount = *max_element(count.begin(), count.end());
            int len = j - i + 1;
            if (len - maxCount <= k)
                res = max(res, len);
        }
    }
    return res;
}
```

### Approach 2 - Improvised Brute Force

Time Complexity - O(26 * n^2)

```cpp
int characterReplacement(string s, int k) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        vector<int> count(26, 0);
        int maxCount = 0;
        for (int j = i; j < n; j++) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            int len = j - i + 1;
            if (len - maxCount <= k)
                res = max(res, len);
        }
    }
    return res;
}
```


### Approach 3 (Sliding Window)

Time Complexity: O(n)

```cpp
int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int left = 0, maxCount = 0, res = 0;
    
    for (int right = 0; right < (int)s.size(); right++) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);
        
        // If too many characters to replace, shrink window
        while ((right - left + 1) - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        
        res = max(res, right - left + 1);
    }
    return res;
}
```