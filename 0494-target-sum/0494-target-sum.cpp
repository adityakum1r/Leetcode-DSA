class Solution {
public:
    int solve(vector<int>&nums,int target,int sum,int idx,int totalsum, vector<vector<int>>&dp ){
        // base case
        if(idx==nums.size()){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[idx][sum+totalsum]!=-1){
            return dp[idx][sum+totalsum];
        }
        // recursive fn
        int plus = solve(nums,target,sum+nums[idx],idx+1,totalsum,dp);
        int minus = solve(nums,target,sum-nums[idx],idx+1,totalsum,dp);
         return dp[idx][sum+totalsum] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int idx=0;
        int sum=0;
        int n=nums.size();
         int totalsum=0;
        for(auto i:nums){
            totalsum+=i;
        }
        vector<vector<int>>dp(n+1,vector<int>(2*totalsum+1,-1));
        return solve(nums,target,sum,idx,totalsum,dp);
    }
};