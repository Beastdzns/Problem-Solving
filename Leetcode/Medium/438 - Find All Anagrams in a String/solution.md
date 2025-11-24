# Solution

## Approach 1 - Sliding Window

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        if(p.size() > n)
            return {};
        vector<int> res;
        vector<int> sFreq(26,0), pFreq(26,0);
        for(char x: p){
            pFreq[x - 'a']++;
        }
        int k = p.size(), l = 0,r = 0;
        for(r;r<k;r++){
            sFreq[s[r] - 'a']++;
        }
        if(sFreq == pFreq)
            res.push_back(l);
        while(r < n){
            sFreq[s[l] - 'a']--;
            sFreq[s[r] - 'a']++;
            l++; r++;
            if(sFreq == pFreq)
                res.push_back(l);
        }
        return res;
    }
};
```