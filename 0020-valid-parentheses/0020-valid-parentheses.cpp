class Solution {
public:
    bool isValid(string s) {
        
        stack<char>paranthesis;
        for(char c: s){
            if(c == '(' || c == '{' || c == '['){
                paranthesis.push(c);
            }
            else{
                if(c==')'){
                    if(!paranthesis.empty()&&paranthesis.top()=='(' ) paranthesis.pop();
                    else return false;
                }
                if(c=='}'){
                    if(!paranthesis.empty() && paranthesis.top()=='{') paranthesis.pop();
                    else return false;
                }
                if(c==']'){
                    if(!paranthesis.empty() && paranthesis.top()=='[') paranthesis.pop();
                    else return false;
                }
            }
        }
        // while(!paranthesis.empty()){
        //     cout<<paranthesis.top()<<endl; 
        //     paranthesis.pop();
        // } 

        if(paranthesis.empty()) return true;
        else return false;
        
    }
};