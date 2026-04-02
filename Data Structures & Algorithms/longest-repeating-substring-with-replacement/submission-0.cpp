class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi=0;
        int count=0;
        unordered_map<char,int> pq;
        
        int l=0;int r=0;

        while(r<s.length()){
            pq[s[r]]++;
            maxi=max(maxi,pq[s[r]]);

            while((r-l+1)-maxi > k){
                pq[s[l]]--;
                l++;
            }
            count=max(count,r-l+1);
            r++;
        }
        return count;
    }
};
