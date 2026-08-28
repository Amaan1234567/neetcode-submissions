class Solution {
public:
    bool isPalindrome(string s) {
        string new_str;
        
        for(auto ele: s){
            ele = char(std::tolower(char(ele)));
            if((int(ele)>=97 && int(ele)<=122) || (int(ele)>=48 && int(ele)<=57)){
                new_str.push_back(ele);
                // std::cout<<ele;
            }
        }
        for(int i=0;i<new_str.size();i++){
            if(new_str[i] != new_str[new_str.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
