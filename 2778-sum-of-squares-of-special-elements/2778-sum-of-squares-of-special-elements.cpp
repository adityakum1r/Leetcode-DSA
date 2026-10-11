class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                long long mul =1LL * nums[i-1]*nums[i-1];
                ans+=mul;
            }
        }
        return ans;
    }
};