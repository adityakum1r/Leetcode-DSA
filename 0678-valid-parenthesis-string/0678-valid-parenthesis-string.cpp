class Solution {
public:
    bool solve(int idx,int balance,string &s,vector<vector<int>>&dp){
     int n = s.length();
     if(balance<0) return false;
     if(idx==n){
        if(balance==0) return true;
        return false;
     }
     if(dp[idx][balance]!=-1){
        return dp[idx][balance];
     }
     bool skip = false;
     bool toopen = false;
     bool toclose = false;
     if(s[idx] == '(') skip = solve(idx+1,balance+1,s,dp);
     else if(s[idx]==')') skip = solve(idx+1,balance-1,s,dp);
     else{
        skip = solve(idx+1,balance,s,dp);
        toopen = solve(idx+1,balance+1,s,dp);
        toclose = solve(idx+1,balance-1,s,dp);
     }
     return dp[idx][balance] = skip || toopen|| toclose;
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        bool ans = solve(0,0,s,dp);
        return ans;
    }
};