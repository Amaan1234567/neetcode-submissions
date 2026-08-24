class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> data;

        for(auto ele: strs){
            vector<int> mp(26,0);
            for(auto ch: ele){
                mp[ch-'a'] += 1;
            }
            string hash;
            hash.push_back('[');
            for(auto e:mp){
                hash.push_back(char('0'+e));
                hash.push_back(',');
            }
            hash.push_back(']');
            // cout<<hash<<std::endl;
            if(data.contains(hash)){
                data[hash].push_back(ele);
            }
            else{
                vector<string> res= {ele};
                data[hash]=res;
            }
        }
        for(auto ele:data){
            // cout<<std::endl;
            // for(auto ch: ele.second){
            //     cout<<ch<<",";
            // }
            // cout<<std::endl;
            
            ans.push_back(ele.second);
        }
        return ans;
    }
};
