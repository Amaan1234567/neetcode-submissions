class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto num:nums){
            if(mp.contains(num)){
                mp[num]+=1;
            }else {
                mp[num]=1;
            }
        }
        vector<pair<int,int>> temp;
        for(auto ele:mp){
            temp.push_back(ele);
        }
        sort(temp.begin(), temp.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;

    }
};
