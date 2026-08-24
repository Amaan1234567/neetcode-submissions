#include <utility>
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> temp(nums.size()+1);
        for (auto num : nums) {
            if (mp.contains(num)) {
                mp[num] += 1;
            } else {
                mp[num] = 1;
            }
        }
        for (auto ele : mp) {
            temp[ele.second].push_back(ele.first);
        }
        int count = 0;
        vector<int> ans;
        for (int i = temp.size()-1; i >= 0; i--) {
            if(count == k){
                break;
            }
            if (temp[i].size() == 0) {
                // cout<<"size:0, continuing"<<std::endl;
                continue;
            }

            count += temp[i].size();
            for (auto ele : temp[i]) {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};
