class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        string ans;
        vector<int> lengths;
        string temp;
        for(string ele:strs){
            temp.append(ele);
            lengths.push_back(ele.size());
        }
        ans.append("[");
        ans.append(std::to_string(strs.size()));
        ans.append("]");
        ans.append("{");
        for(int ele:lengths){
            ans.append(std::to_string(ele));
            ans.append(",");
        }
        ans.pop_back();
        ans.append("}");
        ans.append(temp);
        return ans;
    }

    vector<string> decode(string s) {
        if(s.size()==0){
            return {};
        }
        // std::cout<<"encoded string: "<<s<<std::endl;
        int i=1;
        string size;
        while(s[i]!=']'){
            size.push_back(s[i]);
            i++;
        }
        int len = std::stoi(size);
        i+=2;
        vector<int> lengths;
        string temp;
        // std::cout<<"inside lengths decode: "<<std::endl;
        while(s[i]!='}'){
            // cout<<s[i];
            if(s[i]!=','){
                temp.push_back(s[i]);
            } else {
                lengths.push_back(std::stoi(temp));
                temp.clear();
            }
            i++;
        }
        lengths.push_back(std::stoi(temp));
        // cout<<std::endl;
        // cout<<"size: "<<len<<std::endl;
        // cout<<"lengths.size: "<<lengths.size()<<std::endl;
        // for(auto ele:lengths){
        //     cout<<ele<<",";
        // }
        // cout<<std::endl;
        i++;
        int idx = 0;
        int j = 0;
        vector<string> ans(len);
        string t;
        // std::cout<<"decode debug: "<<std::endl;
        while(i < s.size() && idx < lengths.size()){
            // std::cout<<s[i];
            if(j<lengths[idx]){
                t.push_back(s[i]);
                i++;
                j++;
                
            }else{
                // std::cout<<std::endl<<"first word extracted"<<std::endl;
                // std::cout<<t<<std::endl;
                ans[idx]=t;
                t.clear();
                idx+=1;
                j=0;
            }
        }
        ans[idx--]=t;
        return ans;

    }
};
