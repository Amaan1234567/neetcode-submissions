#pragma GCC optimise("O3","unroll-loops");

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = rows*cols -1;
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(target > matrix[m/cols][m%cols]){
                l = m+1;
            } else if (target < matrix[m/cols][m%cols]){
                r = m-1;
            } else {
                return true;
            }
        }
        return false;
    }
};
