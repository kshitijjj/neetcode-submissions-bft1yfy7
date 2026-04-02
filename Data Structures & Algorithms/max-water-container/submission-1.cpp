class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int s=0;int e=n-1;
        int maxi=INT_MIN;

        while(s<e){
            int w=e-s;
            int ht=min(heights[s],heights[e]);
            int area=w*ht;
            maxi=max(maxi,area);
            heights[s] > heights[e]?e--:s++;
        }
        return maxi;
    }
};
