class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n=temperatures.size();

        for(int i=0;i<n;i++){
            int count=1;
            bool ans1=false;
            for(int j=i+1;j<n;j++){
                if(temperatures[j] > temperatures[i]){
                    ans1=true;
                    ans.push_back(count);
                    break;
                }
                count++;
            }
            if(ans1==false)ans.push_back(0);
        }
        return ans;
    }
};
