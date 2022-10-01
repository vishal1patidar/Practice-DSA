class Solution {
public:
	int f(int i,int sum){
		if(i==1) return 1; 
		int notpick=f(i-1,sum);
		int pick=0;
		if(sum>=i) pick=i*f(i,sum-i);
		return max(pick,notpick);
	}

	int integerBreak(int n){
		return f(n-1,n);
	}
}; 