#pragma GCC optimize("O3");

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        } else if(nums.size()==1){
            return 1;
        }
        unordered_set<int> st;
        int min = INT_MAX;
        int max = INT_MIN;
        for(auto ele:nums){
            st.insert(ele);
        }
        vector<int> sequence_starters;
        for(auto ele:nums){
            if(!st.contains(ele-1)){
                sequence_starters.push_back(ele);
            }
        }
        int max_count=1;
        for(auto ele:sequence_starters){
            int c=1;
            if(st.contains(ele)){
                while(st.contains(ele+1)){
                    ele += 1;
                    c+=1;
                }
            }
            // std::cout<<c<<std::endl;
            max_count = std::max(max_count, c);
        }
        return max_count;
    }
};
