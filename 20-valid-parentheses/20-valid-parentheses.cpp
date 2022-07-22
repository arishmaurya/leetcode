class Solution {
public:
    bool isValid(string str) 
    {
        stack<char>st;
        for(int i=0; i<str.length(); i++)
        {
            char s=str[i];
            
            if(s=='('|| s=='{'|| s=='[')
            {
                st.push(s);
            }
            else {
                if(!st.empty())
                {
                    
                
                 if(st.top()=='('&& s==')'|| st.top()=='{'&& s=='}'|| st.top()=='['&& s==']')
                    {
                    st.pop();
                    }
                    else return false;
                    
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};