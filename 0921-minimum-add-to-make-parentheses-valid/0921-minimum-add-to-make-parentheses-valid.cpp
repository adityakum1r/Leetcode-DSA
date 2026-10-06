class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;

        int ans = 0;

        for(char ch : s) {
            if(ch == '(')
            open++;
            else if(ch == ')' && close == open) 
            ans++;
            else if(ch == ')') 
            close++; 
        } 

        return ans + open - close;        
    }
};