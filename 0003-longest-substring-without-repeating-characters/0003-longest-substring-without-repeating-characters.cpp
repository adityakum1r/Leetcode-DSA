class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        int i=0;
        int j=0;
        int maxlen = 0;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            int length = j-i+1;
            maxlen = max(maxlen,length);
            j++;
        }
        return maxlen;
    }
};