class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int r=matrix.size()-1;
        int m;
        int rows = matrix.size();
        int cols = matrix[0].size();
        while(l<=r){
            m = l+(r-l)/2;
            if(target>matrix[m][cols-1]){
                l = m+1;
            } else if(target == matrix[m][cols-1]) {
                return true;
            } else {
                int l2=0;
                int r2=cols-1;
                int m2;
                while(l2<=r2){
                    m2 = l2+(r2-l2)/2;
                    if(target>matrix[m][m2]){
                        l2 = m2+1;
                    } else if( target < matrix[m][m2]){
                        r2 = m2-1;
                    } else {
                        return true;
                    }
                }
                r = m-1;
            }
        }
        return false;
    }
};
