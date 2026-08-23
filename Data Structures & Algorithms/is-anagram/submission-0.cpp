
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> m = vector(26,0);
        if(s.size() != t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']+=1;
            m[t[i]-'a']-=1;
        }

        for(int data: m){
            if(data != 0){
                return false;
            }
        }
        return true;        
    }
};
