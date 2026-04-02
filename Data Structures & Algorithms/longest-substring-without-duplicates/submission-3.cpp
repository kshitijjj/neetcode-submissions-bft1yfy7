class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0;
        unordered_map<char,int> pq;
        int maxi=0;

        for(int i=0;i<s.length();i++){
            pq[s[i]]++;

            while(pq[s[i]] > 1){
                pq[s[j]]--;
                if(pq[s[j]] == 0)pq.erase(s[j]);
                j++;
            }

            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};
