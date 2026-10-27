class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }else if(s.size() == 1){
            return 1;
        }
        int l = 0;
        int r = 1;
        int max_len = 0;
        set<int> st;
        st.insert(s[l]);
        while(l<=r && r<s.size()){
            if(st.contains(s[r])){
                st.erase(s[l]);
                l++;
                max_len = max(max_len,r-l+1);
            }else{
                st.insert(s[r]);
                r++;
            }
        }
        max_len = max(max_len,r-l);
        return max_len;
    }
};
