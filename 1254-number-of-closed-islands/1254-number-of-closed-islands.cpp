class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int row,int cols){
       int m = grid.size();
        int n = grid[0].size();    
        //base case..
        if(row<0 || cols<0 || row>=m || cols >=n){
            return false;
        }
        if(grid[row][cols]==1){
            return true;
        }
        grid[row][cols]=1;
        bool left = dfs(grid,row,cols-1);
        bool right = dfs(grid,row,cols+1);
        bool top = dfs(grid,row-1,cols);
        bool bottom = dfs(grid,row+1,cols);
        return (left && right && top && bottom) ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
    };
