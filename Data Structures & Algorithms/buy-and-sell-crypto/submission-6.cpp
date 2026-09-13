class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        int l = 0;
        int r = 1; 
        int max_profit=0;
        while(r<prices.size()){
            if(prices[l]>prices[r]){
                l=r;
                r++;
            } else {
                max_profit = max(max_profit,prices[r]-prices[l]);
                r++;
            }
        }
        return max_profit;
    }
};
