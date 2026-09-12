class Solution {
public:
    int findMin(vector<int> &nums) {
        
        if(nums.size()==1 || nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(nums[l]>nums[r]){
            r--;
            
        }
        return nums[r+1];
    }
};
