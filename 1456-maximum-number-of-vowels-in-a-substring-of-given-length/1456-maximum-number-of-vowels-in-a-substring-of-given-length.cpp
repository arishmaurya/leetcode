class Solution {
public:
    int maxVowels(string s, int k) {
        //      int cnt=0;
        // int maxCnt=0;
        // for(int i=0; i<s.size(); i++){
        //     string temp=s.substr(i,k);
        //     for(int j=0; j<3;j++){
        //         if(temp[j]=='a'||temp[j]=='e'||temp[j]=='i'||temp[j]=='o'||temp[j]=='u'){
        //             cnt++;
        //         }
        //         else continue;
        //     }
        //     maxCnt=max(cnt,maxCnt);
        //     cnt=0;
        // }
        // return  maxCnt;
                unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        
        // Build the window of size k, count the number of vowels it contains.
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += vowels.count(s[i]);
        } 
        int answer = count;
        
        // Slide the window to the right, focus on the added character and the
        // removed character and update "count". Record the largest "count".
        for (int i = k; i < s.length(); i++) {
            count += vowels.count(s[i]) - vowels.count(s[i - k]);
            answer = max(answer, count);
        }
        
        return answer;
    }
};