#pragma GCC optimize("O3,unroll-loops")


#include <iostream>

static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            
            unordered_set<char> row_check;
            unordered_set<char> column_check;
            unordered_set<char> grid_check;
            int x=0+i/3;
            
            int y=0+i%3;
            for(int j=0;j<9;j++){

                if(row_check.contains(board[i][j])){
                    return false;
                } else if(board[i][j] != '.'){
                    row_check.insert(board[i][j]);
                }

                if(column_check.contains(board[j][i])){
                    return false;
                } else if(board[j][i] != '.'){
                    column_check.insert(board[j][i]);
                }
                // std::cout<<"x_idx: "<<x*3+j/3<<"  y_idx: "<<y*3+j%3<<std::endl;
                if(grid_check.contains(board[x*3+j/3][y*3+j%3])){
                    // std::cout<<"grid_check: "<<std::endl;
                    // for(auto ele:grid_check){
                    //     std::cout<<ele<<",";
                    // }
                    // std::cout<<std::endl<<"grid["<<x*3+j/3<<']'<<'['<<y*3+j%3<<']'<<std::endl;
                    // std::cout<<"returning false"<<std::endl;
                    return false;
                } else if(board[x*3+j/3][y*3+j%3] != '.'){
                    grid_check.insert(board[x*3+j/3][y*3+j%3]);
                }
            }
            // std::cout<<"outside inner loop"<<std::endl;
        }
        return true;
    }
};
