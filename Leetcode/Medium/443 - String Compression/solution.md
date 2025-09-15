### Solution 1:

Topics: Two Pointers, String

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int k = 0;
        while (i < n) {
            int count = 0;
            char curr_char = chars[i];
            while (i < n && chars[i] == curr_char) {
                count++;
                i++;
            }
            chars[k] = curr_char;
            k++;
            if (count > 1) {
                string cnt = to_string(count);
                for (auto ch : cnt) {
                    chars[k] = ch;
                    k++;
                }
            }
        }
        return k;
    }
};
```