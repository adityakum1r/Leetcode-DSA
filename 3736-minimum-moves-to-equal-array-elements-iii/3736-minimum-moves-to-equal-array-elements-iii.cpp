class Solution {
public:
    int minMoves(vector<int>& nums) {
       int max = INT_MIN;
       for(auto i :nums){
          if(i>max){
            max=i;
          }
       }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max){
                continue;
            }
            else{
                ans+=(max-nums[i]);
            }
        }
        return ans;
    }
};