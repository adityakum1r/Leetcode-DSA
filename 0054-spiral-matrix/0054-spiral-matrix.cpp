class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top = 0;
        int left=0;
        vector<int>ans;
        int bottom = m-1;
        int right =n-1;
        int total_element = m*n;
        int count=0;
        while(count<total_element){
            for(int i=left;i<=right&&count<total_element;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for(int j=top;j<=bottom&&count<total_element;j++){
                ans.push_back(matrix[j][right]);
                count++;
            }
            right--;
            for(int i=right;i>=left&&count<total_element;i--){
                 ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            for(int j=bottom;j>=top&&count<total_element;j--){
                 ans.push_back(matrix[j][left]);
                count++;
            }
            left++;
        }
       

return ans;
    }
};