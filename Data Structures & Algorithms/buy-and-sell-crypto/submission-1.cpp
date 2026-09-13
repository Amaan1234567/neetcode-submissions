class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> suffix(prices.size());
        int max_suf = INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            max_suf = max(max_suf,prices[i]);
            suffix[i] = max_suf;
            std::cout<<suffix[i]<<',';
        }
        int max_profit = -1;
        for(int i=0;i<prices.size();i++){
            max_profit = max(max_profit,suffix[i]-prices[i]);
        }
        return max_profit;
    }
};
