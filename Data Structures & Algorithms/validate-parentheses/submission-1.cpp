class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ele:s){
            if(ele == '('|| ele == '[' || ele == '{' ){
                st.push(ele);
            } else {
                if(st.size()==0){
                    return false;
                }
                if((ele == ')' && st.top()=='(') || (ele == ']' && st.top()=='[') || (ele == '}' && st.top()=='{')){
                    st.pop();
                } else{
                    return false;
                }
            }
        }
        if(st.size()!=0){
            return false;
        }
        return true;
    }
};
