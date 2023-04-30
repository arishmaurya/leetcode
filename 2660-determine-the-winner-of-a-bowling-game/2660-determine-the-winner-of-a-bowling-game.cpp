class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        
       
        int cnt1=0;

        int cnt2=0;

        for(int i=0;i<player1.size(); i++){
            if(i>1&&(player1[i-1]==10|| player1[i-2]==10)) {
                cnt1+= 2*player1[i];
                
            }
            
            else if(i==1 && player1[i-1]==10) cnt1+=2*player1[i];
            else{
                cnt1+=player1[i];
            }
        }
            for(int i=0;i<player2.size(); i++){
            if(i>1 && (player2[i-1]==10|| player2[i-2]==10)) {
                cnt2+= 2*player2[i];
                
            }
            
            else if(i==1&&player2[i-1]==10) cnt2+=2*player2[i];
            else{
                cnt2+=player2[i];
            }
        }
        if(cnt1>cnt2) return 1;
        else if(cnt2>cnt1)return 2;
        return 0;
            
    }
};