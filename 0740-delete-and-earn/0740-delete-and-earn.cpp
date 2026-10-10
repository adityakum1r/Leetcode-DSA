class Solution {
public:
    int solve(vector<int>& nums,int idx,vector<int>&dp){
        int n = nums.size();
        
        // base case..
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        // recursive function;
        int include = 0;
        include+=(nums[idx] + solve(nums,idx+2,dp));
        int exclude = solve(nums,idx+1,dp);
        return dp[idx] = max(include,exclude);
    }
    int deleteAndEarn(vector<int>& nums) {
       int maxval = INT_MIN;
       for(auto i:nums){
        maxval = max(maxval,i);
       }
       vector<int>points(maxval+1,0);
       for(int num:nums){
        points[num]+=num;
       }
       int idx=0;
       vector<int>dp(maxval+1,-1);
       int ans = solve(points,idx,dp);
       return ans;
    }
};