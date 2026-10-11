class Solution {
public:
  int solve(string &s,int idx,vector<int>&dp){
    int n = s.length();
    if(idx==n){
        return 1;
    }
    if(s[idx]=='0'){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int ans = solve(s,idx+1,dp);
    if(idx+1<n){
    if(s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6')){
     ans+= solve(s,idx+2,dp);
    }
    }
    return dp[idx] =  ans;
  }
    int numDecodings(string s) {
        int idx=0;
        vector<int>dp(s.length()+1,-1);
        return solve(s,idx,dp);
    }
};