class Solution {
public:
   int solve(vector<int>& nums,int curr,int prev,vector<vector<int>>&dp){
    if(curr>=nums.size()){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    int includeAns = 0;
    if(prev==-1 || nums[curr]>nums[prev]){
           includeAns = 1 + solve(nums,curr+1,curr,dp);
    }
    int excludeAns = 0 + solve(nums,curr+1,prev,dp);
    int ans = max(includeAns,excludeAns);
    dp[curr][prev+1]=ans;;
    return ans;
   }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans =  solve(nums,curr,prev,dp);
        return ans;

    }
};