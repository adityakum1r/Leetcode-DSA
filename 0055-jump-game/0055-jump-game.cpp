class Solution {
public:
    bool solve(vector<int>& nums,int idx,vector<int>&dp){
        //base case
        if(idx==nums.size()-1){
            return true;
        }
        if(idx>nums.size()){
            return false;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        //recursion..
        int element = nums[idx];
        bool ans = false;
        for(int i=1;i<=element;i++){
           ans = ans ||  solve(nums,idx+i,dp);
        }
        return dp[idx] = ans;
    }
    bool canJump(vector<int>& nums) {
       int idx=0;
       if(nums.size()==1){
        return true;
       }
       int n = nums.size();
       vector<int>dp(n+1,-1);
       return solve(nums,idx,dp);
    }
};