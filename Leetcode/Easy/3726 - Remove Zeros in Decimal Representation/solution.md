### Solution 1

``` cpp
class Solution {
public:
    long long removeZeros(long long n) {
        string binary = to_string(n);
        string ans = "";
        for(int i=0;i<binary.size();i++) {
            if(binary[i] != '0')
                ans += binary[i];
        }
        return stoll(ans);
    }
};
```

