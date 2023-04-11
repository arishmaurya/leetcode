class Solution {
public:
    string removeStars(string s) {
        string str="";
        for(auto i:s)
        {
            if(str.empty()==false && i=='*' )
            {
                str.pop_back();
            }
            else
            {
                str.push_back(i);
            }
        }
        return str;
    }
};