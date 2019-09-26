class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int i = 0, j = 1;
		int maxlen = 0;
        if(s == "") return 0;
		while (i<s.length() && j<s.length()) {
			int pos;
			string str = s.substr(i, j - i);
			if (pos = isin(s[j], str) == -1) {
				j++;
			}
			else {
				maxlen = maxlen > j - i  ? maxlen : j - i;
				i = j-(str.length()-pos)+1;
			}
		}
		return maxlen > j - i ? maxlen : j - i;
	}

	int isin(char c, string s) {
		int found = s.rfind(c);
		if (found == string::npos) {
			return -1;
		}
		else {
			return found;
		}
	}
};