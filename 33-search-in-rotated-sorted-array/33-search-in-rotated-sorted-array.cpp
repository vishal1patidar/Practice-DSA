class Solution {
public:
	int search(vector<int>& a, int target) {
		int l=0,r=a.size()-1;
		while(l<r) {
			int m=(l+r)/2;
			if(a[m]>a[r]) l=m+1;
			else r=m;
		}
		int rot=r;
		l=0,r=a.size()-1;
		while(l<=r) {
			int m=(l+r)/2;
			int modifiedM=(rot+m)%a.size();
			if(a[modifiedM]>target) r=m-1;
			else if(a[modifiedM]<target) l=m+1;
			else return modifiedM;
		}
		return -1;
	}
};