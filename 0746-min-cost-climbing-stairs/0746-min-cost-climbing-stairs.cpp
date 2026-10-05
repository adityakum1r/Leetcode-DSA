class Solution {
public:
    int solve(vector<int>& cost,int idx, vector<int>&dp){
        // base case
        if(idx>=cost.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        // recursive function
        int onestep = cost[idx] + solve(cost,idx+1,dp);
        int twostep = cost[idx] + solve(cost,idx+2,dp);
        return dp[idx] = min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return  min(solve(cost,0,dp),solve(cost,1,dp));
    }
};