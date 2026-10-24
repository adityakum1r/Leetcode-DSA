class Solution {
public:
    bool isAnagram(string s, string t) {
       int arr[200];
       for(int i=0;i<s.size();i++){
        char ch = s[i];
        arr[ch]++;
       } 
       for(int j=0;j<t.size();j++){
        char ch = t[j];
        arr[ch]--;
       }
       for(int i=0;i<200;i++){
        if(arr[i]!=0){
            return false;
        }
       }
       return true;
    }
};