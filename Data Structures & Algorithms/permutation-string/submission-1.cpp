class Solution {
public:
    bool solve(vector<int>& freq1,vector<int>& freq2){
        return freq1==freq2;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);

        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }

        int windsize=s1.length();

        for(int i=0;i<s2.length();i++){
            int widx=0;int idx=i;
            vector<int> freq2(26,0);
            while(widx < windsize && idx < s2.length()){
                freq2[s2[idx]-'a']++;
                widx++;idx++;
            }
            if(solve(freq1,freq2))return true;
        }
        return false;
    }
};
