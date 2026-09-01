class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxprefix;
        vector<int> maxsuffix(height.size());
        int max_pre=0;
        int max_suf=0;
        maxprefix.push_back(0);
        maxsuffix[height.size()-1]=0;
        for(int i=1;i<height.size();i++){
            maxprefix.push_back(max(max_pre,height[i-1]));
            maxsuffix[height.size()-1-i]=max(max_suf,height[height.size()-i]);
            max_pre = max(max_pre,height[i-1]);
            max_suf = max(max_suf,height[height.size()-i]);
        }
        // std::cout<<"max_prefix:"<<std::endl;
        // for(auto ele:maxprefix){
        //     std::cout<<ele<<",";
        // }
        // std::cout<<std::endl;

        // std::cout<<"max_suffix:"<<std::endl;
        // for(auto ele:maxsuffix){
        //     std::cout<<ele<<",";
        // }
        // std::cout<<std::endl;

        int total = 0;
        for(int i=0;i<height.size();i++){
            total+= max(0,min(maxprefix[i],maxsuffix[i])-height[i]);
        }
        return total;
    }
};
