class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int w=j-i;
                int ht=min(heights[i],heights[j]);
                int area=w*ht;
                maxi=max(maxi,area);
            }
        }
        return maxi;
    }
};
