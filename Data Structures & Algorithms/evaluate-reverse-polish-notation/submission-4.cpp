class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto ele:tokens){
            if(ele.size() ==1 && (ele[0] == '+' || ele[0] == '-' || ele[0] == '*' || ele[0] == '/')){
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                switch(ele[0]) {
                    case '+':
                    st.push(ele1+ele2);
                    break;
                    case '-':
                    st.push(ele2-ele1);
                    break;
                    case '*':
                    st.push(ele1*ele2);
                    break;
                    case '/':
                    st.push(ele2/ele1);
                    break;
                    default:break;
                }
            } else {
                st.push(std::stoi(ele));
            }
            // std::cout<<st.top()<<std::endl;
        }
        return st.top();
    }
};
