class Solution {
public:
  int solveusingrec(string text1, string text2,int i,int j){
     // base case
     if(i==text1.length()){
        return 0;
     }
     if(j==text2.length()){
        return 0;
     }
     if(text1[i]==text2[j]){
        return 1+solveusingrec(text1,text2,i+1,j+1);
     }
     else{
        return 0+max(solveusingrec(text1,text2,i+1,j),solveusingrec(text1,text2,i,j+1));
     }
      

  }
  int solveusingmemo(string &text1, string &text2,int i,int j,vector<vector<int>>&dp){
     // base case
     if(i==text1.length()){
        return 0;
     }
     if(j==text2.length()){
        return 0;
     }
     int ans = 0;
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     if(text1[i]==text2[j]){
        ans =  1+solveusingmemo(text1,text2,i+1,j+1,dp);
     }
     else{
       ans =  0+max(solveusingmemo(text1,text2,i+1,j,dp),solveusingmemo(text1,text2,i,j+1,dp));
     }
      dp[i][j]=ans;
      return ans;

  }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length(),-1));
        return solveusingmemo(text1,text2,i,j,dp);
    }
};