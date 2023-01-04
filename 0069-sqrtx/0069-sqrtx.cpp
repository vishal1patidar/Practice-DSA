class Solution {
public:
	int mySqrt(int x) {
		int i=0, j=x, ans;
		while(i<=j){
			long long int mid=i+(j-i)/2;
			if(mid*mid==x){ans = mid; break;}
			else if(mid*mid<x){i=mid+1;}
			else{j=mid-1;}
		}
		return ans;
	}
};