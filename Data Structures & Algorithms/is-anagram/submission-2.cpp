class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> pq;
        unordered_map<char,int> mp;

        for(auto i:s){
            pq[i]++;
        }
        for(auto i:t){
            mp[i]++;
        }

        if(pq.size()!=mp.size())return false;

        for(int i=0;i<s.length();i++){
            if(pq[s[i]] != mp[s[i]])return false;
        }
        return true;
    }
};
