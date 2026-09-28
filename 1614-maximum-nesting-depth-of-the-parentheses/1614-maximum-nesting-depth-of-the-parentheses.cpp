class Solution {
public:
// int len(string &s){
//     int cnt=0;
//     for(auto i:s){
//         if(isdigit(i)){
//             cnt++;
//         }
//         else{
//             continue;
//         }
//     }
//     return cnt;
// }
    int maxDepth(string s) {
        int count=0;
        int n = s.length();
        int idx=0;
        vector<int>tmp(n,0);
        for(auto i:s){
            if(i=='('){
                count++;
            }
            else if(i==')'){
                  tmp[idx]=count;
                  count--;
                  idx++;
            }
            else{
                continue;
            }
        }
        int max = INT_MIN;
        for(auto i:tmp){
            if(i>max){
                max=i;
            }
        }
        return max;
    }
};