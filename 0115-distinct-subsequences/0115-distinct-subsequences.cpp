class Solution {
public:
    int solve(int i,int j,string &s, string &t, vector<vector<int>>&dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int include = 0;
        if(s[i]==t[j]){
            include = solve(i-1,j-1,s,t,dp);
        }
        int exclude = solve(i-1,j,s,t,dp);
        int ans = include+exclude;
        dp[i][j]=ans;
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};