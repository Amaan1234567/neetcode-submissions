class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        for(auto ele:piles){
            l = min(l,ele);
            r = max(r,ele);
        }
        int k;
        int hours;
        while(l<=r){

            vector<int> piles_c = piles;
            hours = h;
            k = l +(r-l)/2;
            for(auto ele:piles_c){
                // std::cout<<"calc: "<<std::ceil((double)ele/(double)k)<<std::endl;
                hours -= max((int)std::ceil((double)ele/(double)k),1);
            }
            // std::cout<<"hours: "<<hours<<",k: "<<k<<std::endl;
            if(hours < 0){
                l = k+1;
            } else if(hours == 0) {
                r = k-1;
            } else if(hours > 0){
                r = k-1;
            }
        }
        if(hours <0){
            return k+1;
        }else{
            return k;
        }
    }
};
