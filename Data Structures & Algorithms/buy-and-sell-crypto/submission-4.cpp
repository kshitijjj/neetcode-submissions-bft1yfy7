class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l=0;
        int maxi=INT_MIN;
        int r=1;

        while(r<prices.size()){
            if(prices[l] < prices[r]){
                maxi=max(maxi,prices[r]-prices[l]);
            }
            else {
                l=r;
            }
            r++;
        }
        if(maxi<0)return 0;
        return maxi;
    }
};
