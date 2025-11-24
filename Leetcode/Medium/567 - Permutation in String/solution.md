# Solution

## Approach 1 - Using Sliding Window

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int k = s1.size();
        if(k > n)
            return false;
        vector<int> a(26,0), b(26,0);
        int l = 0, r = 0;
        for(char x: s1){
            a[x - 'a']++;
        }

        for(r;r<k;r++){
            b[s2[r] - 'a']++;
        }
        if(a==b)
            return true;
        while(r < n){
            b[s2[l] - 'a']--;
            b[s2[r] - 'a']++;
            l++;
            r++;
            if(a == b)
                return true;
        }
        return false;
    }
};
```
