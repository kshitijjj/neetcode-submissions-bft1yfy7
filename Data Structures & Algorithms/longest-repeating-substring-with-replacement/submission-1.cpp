class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> pq;

        int i=0;
        int j=0;
        int maxi=0;
        int count=0;

        while(i<s.length()){
            pq[s[i]]++;
            maxi=max(maxi,pq[s[i]]);

            cout << "maxi" << " " << maxi << endl;

            while((i-j+1) - maxi > k ){
                pq[s[j]]--;
                j++;
            }
            count=max(count,i-j+1);
            cout << "i" << " " << i << " " << "j" << " " << j << endl;
            cout << "count" << " " << count << endl;

            i++;
        }
        return count;
    }
};
