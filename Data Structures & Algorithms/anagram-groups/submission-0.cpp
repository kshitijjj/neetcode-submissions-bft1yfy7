class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> pq;


        for(auto i:strs){
            string a=i;
            sort(i.begin(),i.end());
            pq[i].push_back(a);
        }
        vector<vector<string>> ans;
        for(auto i:pq){
            vector<string>temp=i.second;
            ans.push_back(temp);
        }
        return ans;
    }
};
