#include <utility>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> heap;
        for(auto num:nums){
            if(mp.contains(num)){
                mp[num]+=1;
            }else {
                mp[num]=1;
            }
        }
        for(auto ele:mp){
            heap.push(std::make_pair(ele.second,ele.first));
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            pair<int,int> ele = heap.top();
            heap.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};
