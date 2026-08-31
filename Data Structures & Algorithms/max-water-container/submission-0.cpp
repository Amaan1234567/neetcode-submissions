class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area=0;
        int l=0;
        int r=heights.size()-1;
        while(l<r){
            max_area = max(max_area,min(heights[l],heights[r])*(r-l));
            if(heights[l]>=heights[r]){
                r--;
            } else{
                l++;
            }
        }
        return max_area;
    }
};
