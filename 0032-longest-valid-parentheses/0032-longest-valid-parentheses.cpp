class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(close>open){
                close=0;
                open=0;
            }
            if(close==open){
                result = max(result,open+close);
            }
        }
        open=0;
        close=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
              if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
             if(open>close){
                close=0;
                open=0;
            }
            if(close==open){
                result = max(result,open+close);
            }
        }
        return result;
    }
};