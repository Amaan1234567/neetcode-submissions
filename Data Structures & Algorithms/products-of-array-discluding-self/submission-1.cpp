class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_prod;
        vector<int> suffix_prod(nums.size());
        int prod1 = 1;
        int prod2 = 1;
        int j=nums.size()-1;
        int i=0;
        while(i<nums.size() && j>=0){
            prod1*= nums[i];
            prod2*= nums[j];
            prefix_prod.push_back(prod1);
            suffix_prod[j]=prod2;
            i++;j--;
        }
        // std::cout<<"prefix_prod: "<<std::endl;
        // for(int i=0;i<nums.size();i++){
        //     std::cout<<prefix_prod[i]<<",";
        // }
        // std::cout<<std::endl;
        
        // std::cout<<"suffix_prod: "<<std::endl;
        // for(int i=0;i<nums.size();i++){
        //     std::cout<<suffix_prod[i]<<",";
        // }
        // std::cout<<std::endl;
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int final_prod=1;
            if(i==0){
                final_prod *= suffix_prod[i+1];
            }
            if(i == nums.size()-1){
                final_prod *= prefix_prod[i-1];
            }
            if(i !=0 && i != nums.size()-1){
                final_prod *= prefix_prod[i-1]*suffix_prod[i+1];
            }
            ans.push_back(final_prod);
        }
        return ans;
    }
};
