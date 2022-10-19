class Solution {
public:
     vector<string> topKFrequent(vector<string>& words, int k) {
       auto cmp=[](pair<int,string> & p1,pair<int,string> &p2){
                if(p1.first==p2.first){
                    return p1.second<p2.second;
                }
                return p1.first>p2.first;
            };
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
      vector<pair<int,string>> p;
        for(auto it :mp){
            p.push_back(make_pair(it.second,it.first));
        }
        sort(p.begin(),p.end(),cmp);
       for(auto it: p){
           if(k<=0)break;
           ans.push_back(it.second);
           k--;
       }
        return ans;
    }
};