class Solution {
public:
    int solve(int n,int steps,vector<int>&dp){
        //base case
        if(steps>n){
            return 0;
        }
        if(steps==n){
            return 1;
        }
        if(dp[steps]!=-1){
            return dp[steps];
        }
        // recursive function
        int singlestep = solve(n,steps+1,dp);
        int doublestep = solve(n,steps+2,dp);
        return dp[steps] = singlestep+doublestep;
    }
    int climbStairs(int n) {
          int steps=0;
          vector<int>dp(n+1,-1);
          return solve(n,steps,dp);
    }
};