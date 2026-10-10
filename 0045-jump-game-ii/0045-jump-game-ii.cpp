class Solution {
public:
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        //base case..
       
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        // recursion..
        int element = nums[idx];
        int ans = INT_MAX;
        for(int i=1;i<=element;i++){
            int temp = solve(nums,idx+i,dp);
            if(temp!=INT_MAX){
             ans = min(ans,1 + temp);
            }
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
      int n = nums.size();
      int idx=0;
      vector<int>dp(n+1,-1);
      int ans = solve(nums,idx,dp);
      return ans;  
    }
};