class Solution {
public:
    void solve(vector<int>&nums, int val,  vector<int>&ans){
        for(auto i:nums){
            if(i!=val){
                ans.push_back(i);
            }
            else{
                continue;
            }
        }
    }
    int removeElement(vector<int>& nums, int val) {
        vector<int>ans;
        solve(nums,val,ans);
        nums=ans;
        return nums.size();
    }
};