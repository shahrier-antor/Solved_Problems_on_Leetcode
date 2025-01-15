class Solution {
 public:
  int calculate(string s) {
    int ans=0;
    int num = 0;
    int sign = 1;
    stack<int>st{{sign}};
    
    for(char c: s){
        if(isdigit(c)){
            num+= num*10 + (c-'0');
        }
        else if(c=='('){
            st.push(sign);
        }
        else if (c==')'){
            st.pop();
        }
        else if( c == '+' || c == '-'){
            ans += sign*num;
            sign = (c=='+'? 1:-1)*st.top();
            num = 0;
        }

    }
    return ans + num*sign;
  }
  
};