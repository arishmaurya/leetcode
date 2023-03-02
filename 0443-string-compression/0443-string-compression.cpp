class Solution {
public:
   int compress(vector<char>& chars) {
		int currIndex, newIndex;
		currIndex = newIndex = 0;
		int currCount = 1;
		char currChar = chars[0];

		currIndex = 0;
		for (int i = 1; i < chars.size(); ++i) {
			if (chars[i] == currChar) {
				currCount++;
				continue;
			}

			if (currCount == 1) {
				chars[newIndex++] = currChar;
			}
			else {
				chars[newIndex++] = currChar;
				string s = to_string(currCount);
				for (auto it : s)
					chars[newIndex++] = it;
			}
            currChar = chars[i];
            currCount = 1;
		}

		if (currCount == 1) {
			chars[newIndex++] = currChar;
		}
		else {
			chars[newIndex++] = currChar;
			string s = to_string(currCount);
			for (auto it : s)
				chars[newIndex++] = it;
		}
		return newIndex;
	}
};