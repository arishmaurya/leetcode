class Solution {
public:
    bool isPalindrome(int x) {
  long long rev=0,origi=x;
        if(x<0)return 0;
	while (x) {
		rev = (rev * 10) + (x % 10);
		x /= 10;
	}
       return rev==origi;
    }
};