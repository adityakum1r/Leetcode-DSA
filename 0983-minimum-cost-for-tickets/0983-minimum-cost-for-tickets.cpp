class Solution {
public:
    int solve(vector<int>&days, vector<int>& costs,int idx,vector<int>&dp){
        int n = days.size();
        //base case..
        if(idx>=days.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        // recursive fn
        int onedaypass = costs[0] + solve(days,costs,idx+1,dp);
        int i=idx;
        while(i<n && days[i]<days[idx]+7){
            i++;
        }
        int sevendayspass = costs[1]  + solve(days,costs,i,dp);
        int j = idx;
        while(j<n && days[j]<days[idx]+30){
            j++;
        }
        int thirtydayspass = costs[2] + solve(days,costs,j,dp);

        return dp[idx] = min(onedaypass,min(sevendayspass,thirtydayspass));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int idx=0;
        int maxi = INT_MIN;
        for(auto i:days){
            maxi = max(maxi,i);
        }
        vector<int>dp(maxi+30,-1);
        return solve(days,costs,idx,dp);
    }
};