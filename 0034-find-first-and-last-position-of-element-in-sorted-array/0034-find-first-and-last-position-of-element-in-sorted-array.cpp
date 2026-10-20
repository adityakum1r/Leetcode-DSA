class Solution {
public:
 int first_occurence(vector<int>& nums, int target) {
         int st=0;
         int end = nums.size()-1;
         int ans=-1;
         while(st<=end){
            int mid = (st+end)/2;
            if(nums[mid]==target){
                ans=mid;
                end = mid-1;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
         }
         return ans;

    } 
 int last_occurence(vector<int>& nums, int target) {
         int st=0;
         int end = nums.size()-1;
         int ans=-1;
         while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target){
                ans=mid;
                st=mid+1;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
         }
         return ans;

    } 
    vector<int> searchRange(vector<int>& nums, int target) {
       int x = first_occurence(nums,target);
       int y = last_occurence(nums,target);
       
 return {x,y};
    }
};