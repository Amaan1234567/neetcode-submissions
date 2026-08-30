class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // unordered_set<vector<int>> st;
        set<tuple<int,int,int>> st;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1;
            int r = nums.size()-1;
            while(l<r){
                // std::cout<<"l,r: "<<l<<","<<r<<std::endl;
                if(nums[l]+nums[r] == -nums[i]){
                    st.insert(std::make_tuple(nums[i],nums[l], nums[r]));
                    l++;
                } else if(nums[l]+nums[r] < -nums[i]){
                    l++;
                } else {
                    r--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto ele: st){
            auto [one,two,three] = ele;
            ans.push_back({one,two,three});
        }
        return ans;
    }
};
