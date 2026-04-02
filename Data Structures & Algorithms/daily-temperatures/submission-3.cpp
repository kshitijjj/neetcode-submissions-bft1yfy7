class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<pair<int,int>> s;
        int n=temperatures.size();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top().first <= temperatures[i]){
                s.pop();
            }
            if(s.empty())ans.push_back(0);
            else ans.push_back(s.top().second - i);
            s.push({temperatures[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
