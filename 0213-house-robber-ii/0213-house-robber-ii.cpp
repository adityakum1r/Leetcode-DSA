class Solution {
public:
      int solve(vector<int>& nums,int st,int end,vector<int>&dp){
        // base case
        if(st>end){
            return 0;
        }
        if(dp[st]!=-1){
            return dp[st];
        }
        // recursive fn
        int take = nums[st] + solve(nums,st+2,end,dp);
        int notake = solve(nums,st+1,end,dp);
        return dp[st] =max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int ans1= solve(nums,0,n-2,dp1);
        int ans2 = solve(nums,1,n-1,dp2);
        return max(ans1,ans2);
    }
};