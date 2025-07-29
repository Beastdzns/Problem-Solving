```cpp

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r1 = 0;
        int c1 = 0;
        int r2 = matrix.size() - 1;
        int c2 = matrix[0].size() - 1;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        while (true) {
            // Iteration 1
            for (int i = c1; i <= c2; i++) {
                ans.push_back(matrix[r1][i]);
            }
            if(ans.size() == m*n)
                break;
            // Iteration 2
            for (int i = r1+1; i <= r2; i++) {
                ans.push_back(matrix[i][c2]);
            }
            if(ans.size() == m*n)
                break;

            // Iteration 3
            for (int i = c2-1; i >=c1; i--) {
                ans.push_back(matrix[r2][i]);
            }
            if(ans.size() == m*n)
                break;

            // Iteration 4
            for (int i = r2-1; i > r1; i--) {
                ans.push_back(matrix[i][c1]);
            }
            if(ans.size() == m*n)
                break;
            
            //Updation
            r1++; c1++;
            r2--; c2--;
        }

        return ans;
    }
};

```