class Solution {
public:
	int characterReplacement(string s, int k) {
		function<int(char)> fnd=[&](char ch){
			int j=0,l=k,mx=0;
			for(int i=0;i<s.length();i++) {
				if(s[i]!=ch) l--;
				while(l<0) {
					if(s[j]!=ch) l++;
					j++;
				}
				mx=max(mx,i-j+1);
			} 
			return mx;
		};
		int res=0;
		for(int i=0;i<26;i++) {
			res=max(res,fnd(i+'A'));
		}
		return res;
	}
};