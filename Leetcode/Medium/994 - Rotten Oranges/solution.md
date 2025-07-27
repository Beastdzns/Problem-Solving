``` cpp

class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        queue<pair<int,int>> q;
        // First iteration
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    freshOranges++; 
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        q.push({-1, -1});
        int minutes = -1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == -1){
                minutes++;
                if(!q.empty()){
                    q.push({-1, -1});
                }
            } else {
                for(int i=0;i<4;i++){
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];

                    if(x<0 || x>=n || y<0 || y>=m){
                        continue;
                    }
                    if(grid[x][y] == 1){
                        grid[x][y] = 2;
                        freshOranges--;
                        q.push({x,y});
                    }
                    
                }
            }
        }
        if(freshOranges == 0)
            return minutes;
        return -1;
    }
};

```