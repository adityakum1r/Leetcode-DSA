class Solution {
public:
    int solve(vector<int>& nums,int curr,int prev,vector<vector<int>>&dp){
        //base case
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }
        //recursive function
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include = 1+solve(nums,curr+1,curr,dp);
        }
        int exclude = solve(nums,curr+1,prev,dp);
        return dp[prev+1][curr] = max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
       int curr=0;
       int prev=-1;
       int n = nums.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(nums,curr,prev,dp); 
    }
};