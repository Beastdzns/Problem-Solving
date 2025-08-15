### Solution 1

```cpp

class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0;i<n;i++){
            if(pow(4,i) > n)
                return false;
            if(pow(4,i) == n)
                return true;
        }
        return false;
    }
};

```