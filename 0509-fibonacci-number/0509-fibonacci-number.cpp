class Solution {
public:
    int solve(int n,vector<int>&dp){
        //base case
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        //recursive function
        return dp[n] =  solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};