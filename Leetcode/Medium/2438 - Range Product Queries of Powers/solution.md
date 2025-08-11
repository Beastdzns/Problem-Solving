```cpp

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> ans;
        // Conversion
        for (int i = 0; i < 31; i++) { 
            if ((n >> i) & 1) {
                powers.push_back(1 << i); 
            }
        }

        // Logic
        for (auto query : queries) {
            int first = query[0];
            int second = query[1];
            long long computation = 1;
            for (int i = first; i <= second; i++) {
                computation = (computation * powers[i]) % MOD;
            }
            ans.push_back(computation);
        }
        return ans;
    }
};

```