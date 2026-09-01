#pragma GCC optimize("O3","unroll-loops");

class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r = height.size()-1;
        int l_max = height[0];
        int r_max = height[height.size()-1];
        int total = 0;
        while(l<r){
            if(l_max < r_max){
                l++;
                l_max = max(l_max,height[l]);
                total += l_max - height[l];
            } else {
                r--;
                r_max = max(r_max,height[r]);
                total += r_max - height[r];
            }
        }
        return total;
    }
};
