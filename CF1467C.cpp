#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int sz[3];
	ll sum[3];
	for(auto &i:sz)cin>>i;
	vector<ll> v[3];
	vector<ll> vv;
	ll total = 0;
	for(int i = 0;i<3;i++){
		sum[i] = 0;
		for(int j = 0;j<sz[i];j++){
			int k;
			cin>>k;
			v[i].push_back(k);
			sum[i] += k;
			total += k;
		}
		sort(v[i].begin(),v[i].end());
		vv.push_back(v[i][0]);
	}
	sort(vv.begin(),vv.end());
	ll ans = total - vv[0]*2-vv[1]*2;
	for(int i = 0;i<3;i++)ans = max(ans,total-sum[i]*2);
	cout<<ans;
}
