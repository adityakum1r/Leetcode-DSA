class Solution {
public:
    int solve(vector<int>& stones,int idx,int sum,int totalsum,vector<vector<int>>&dp)
    {
        // base case
        if(idx==stones.size()){
            return abs(totalsum-2*sum);
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        //recursive function
        int include = solve(stones,idx+1,sum+stones[idx],totalsum,dp);
        int exclude = solve(stones,idx+1,sum,totalsum,dp);
        return dp[idx][sum] = min(include,exclude);
    } 
    int lastStoneWeightII(vector<int>& stones) {
      int idx=0;
      int sum = 0;
      int totalsum=0;
      for(auto i :stones){
        totalsum+=i;
      }
      vector<vector<int>>dp(stones.size()+1,vector<int>(totalsum+1,-1));
      return solve(stones,idx,sum,totalsum,dp);

    }
};