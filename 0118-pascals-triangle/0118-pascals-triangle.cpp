class Solution {
public:

int ncr(int n,int r){
    long long res = 1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>rows;
            for(int j=0;j<=i;j++){
                rows.push_back(ncr(i,j));
            }
            ans.push_back(rows);
        }
        return ans;
    }
};