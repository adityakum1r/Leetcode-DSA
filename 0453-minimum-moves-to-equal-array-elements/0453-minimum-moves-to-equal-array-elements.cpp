class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min = INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
           if(nums[i]<min){
            min=nums[i];
           }
        }
        for(int i=0;i<n;i++){
            ans+=(nums[i]-min);
        }
        return ans;
    }
};