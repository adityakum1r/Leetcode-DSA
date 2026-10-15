class Solution {
public:
    unordered_set<string>st;
    bool solve(string &s,int idx,vector<int>&dp){
        //base case..
        if(idx==s.length()){
            return true;
        }
        // if(st.find(s)!=st.end()){
        //     return true;
        // }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int l=1;l<=s.length()-idx;l++){
            string temp = s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(s,idx+l,dp)){
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int idx = 0;
        for(auto i: wordDict){
            st.insert(i);
        }
        vector<int>dp(s.length()+1,-1);
        return solve(s,idx,dp);
    }
};