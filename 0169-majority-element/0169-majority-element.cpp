class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int curr_freq=1;
      int max_freq=1;
      int mode=nums[0];
      for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1]){
            curr_freq++;
           }
           else{
            curr_freq=1;
           }
           if(curr_freq>max_freq){
            max_freq=curr_freq;
            mode=nums[i];
           }
      } 
      return mode; 
    }
};