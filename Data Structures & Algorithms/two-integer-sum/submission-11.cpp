#include <algorithm>
#include <utility>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> original_idx;
        for(int i=0;i<nums.size();i++){
            original_idx.push_back(make_pair(nums[i],i));
        }
        sort(original_idx.begin(),original_idx.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first < b.first;
        });
        for(int i=0;i<original_idx.size();i++){
            int true_target = target - original_idx[i].first;
            int l=i+1;
            int r=nums.size()-1;
            int m = 0;
            while(l<=r){
                // cout<<l<<"\n";
                m=(l+r)/2;
                if(original_idx[m].first == true_target){
                    if(original_idx[i].second < original_idx[m].second){
                        return vector({original_idx[i].second,original_idx[m].second});
                    }else{
                        return vector({original_idx[m].second,original_idx[i].second});
                    }
                }
                else if(original_idx[m].first < true_target){
                    l=m+1;
                    
                } else {
                    r = m-1; 
                }
            }
        }
        return vector(0,2);
    }
};
