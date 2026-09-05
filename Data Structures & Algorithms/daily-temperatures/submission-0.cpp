class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.size()==0){
                ans.push_back(0);
                st.push(std::make_pair(temperatures[i], i));
                continue;
            }
             
            while(st.size()>0 && st.top().first <= temperatures[i]){
                st.pop();
            }
            if(st.size()==0){
                ans.push_back(0);
            } else {
                ans.push_back(st.top().second-i);
            }
            
            st.push(std::make_pair(temperatures[i], i));
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
