class Solution {
public:
    using ll=long long;
int numberOfArithmeticSlices(vector<int>&a) {
    int n=a.size();
    vector<map<ll,ll>> dp3(n);
    vector<map<ll,ll>> dp2(n);
    ll ans=0;
    for(ll i=1;i<n;i++) {
    	for(ll j=0;j<i;j++) {
    		ll d=(ll)a[i]-a[j];
    		dp2[i][d]++;
    		auto i1=dp2[j].find(d),i2=dp3[j].find(d);
    		if(i1==dp2[j].end()&&i2==dp3[j].end())
    			continue;
    		ll c=i1->second+i2->second;
    		dp3[i][d]+=c, ans+=c;
    	}
    }
    return ans;
}
};

