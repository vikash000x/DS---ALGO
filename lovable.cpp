Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.

  code==================================================================================
   bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char x : expression){
            if(x==',' || x=='(') continue;
            else if(x=='!' || x=='&' || x=='|' || x=='t' || x=='f') st.push(x);
            else if(x==')'){
                bool hast = false;
                bool hasf = false;
            
             
               while(st.top() != '!' && st.top() != '&' && st.top() != '|'){
                    char y = st.top();
                    st.pop();
                    if(y=='f') hasf = true;
                    if(y=='t') hast = true;
                    
                }
                char l = st.top();
                st.pop();
                if(l == '!') {
                    st.push(hast ? 'f' : 't');
                } else if(l=='&'){
                    st.push(hasf ? 'f' : 't');
                } else if(l=='|'){
                    st.push(hast ? 't' : 'f');
                }
            }

        } return st.top()=='t';
        
    }
