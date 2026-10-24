class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       int result = 0;
       unordered_set<char>st;
       for(auto i:jewels){
          st.insert(i);
       } 
       for(int i=0;i<stones.length();i++){
        char ch = stones[i];
        if(st.find(ch)!=st.end()){
            result+=1;
        }
       }
       return result;
    }
};