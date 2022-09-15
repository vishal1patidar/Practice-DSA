class Solution {
public:
int maxSubArray(vector<int>& x) {

    int n=x.size();


int sum=x[0];
int maxi=x[0];
for(int i=1;i<n;i++)
{
sum = max(x[i], sum+x[i]);
maxi=max(sum, maxi);
}

    return maxi;
}
};