class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){
            return "";
        }
        unordered_map<char,int>mp;
        for(auto i:t){
            mp[i]++;
        }
        int i=0;
        int j=0;
        int count=t.length();
        int start_i=0;
        int min_size=INT_MAX;
        while(j<s.length()){
          char ch = s[j];
          if(mp[ch]>0)
           count--;
          mp[ch]--;
          while(count==0){
            int curr_size = j-i+1;
            if(curr_size<min_size){
                min_size=curr_size;
                start_i=i;
            }
             mp[s[i]]++;
             if(mp[s[i]]>0){
                count++;
             }
             i++;
          }
          j++;
        }
        return min_size==INT_MAX?"":s.substr(start_i,min_size);
    }
};