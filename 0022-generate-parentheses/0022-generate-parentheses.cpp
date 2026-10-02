class Solution {
public:
    bool validparenthesis(string &s){
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                 st.pop();
            }
        }
        return st.empty();
    }
     void generate(int n,string &s,vector<string>&result){
        if(s.length()==2*n){
            if(validparenthesis(s)){
                result.push_back(s);
            }
            return;
        }
        s.push_back('(');
        generate(n,s,result);
        s.pop_back();
        s.push_back(')');
        generate(n,s,result);
        s.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>result;
        generate(n,s,result);
        return result;
    }
};