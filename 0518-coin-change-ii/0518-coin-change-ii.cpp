class Solution {
public:
    int solve(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp){
        //base case
        if(amount==0){
            return 1;
        }
        if(idx>=coins.size()){
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        // recursive function
        int include = 0;
        if(coins[idx]<=amount){
            include = solve(coins,amount-coins[idx],idx,dp);
        }
        int exclude = solve(coins,amount,idx+1,dp);
        return dp[idx][amount] = include+exclude;
    }
    int change(int amount, vector<int>& coins) {
       int idx = 0;
       int n = coins.size();
       vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
       return solve(coins,amount,idx,dp);
    }
};