class Solution {
public:
    bool solve(int i,int j,int count,vector<vector<char>>& grid, vector<vector<vector<int>>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        count+=(grid[i][j]=='(')?+1:-1;
        if(count==-1){
            return false;
        }
        if(i==m-1 && j==n-1){
            return count==0;
            }
        
        //right
        if(dp[i][j][count]!=-1){
            return dp[i][j][count];
        }
        bool right = false;
        bool down = false;
        if(j<n-1){
            // if(solve(i,j+1,count,grid,dp)){
                
            //     return dp[i][j][count] = true;
            // }
             right = solve(i,j+1,count,grid,dp);
        }
        if(i<m-1){
            // if(solve(i+1,j,count,grid,dp))
            //     return dp[i][j][count] = true;
            down = solve(i+1,j,count,grid,dp);
            
        }

        return dp[i][j][count] = right||down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n, -1)));
        if(grid[0][0]==')'){
            return false;
        }
       if((m+n-1)%2==1){
        return false;
       }
        int i=0;
        int j=0;
        int count=0;
        bool ans = solve(i,j,count,grid,dp);
        return ans;
    }
};