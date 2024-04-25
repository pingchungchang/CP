#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int n,q;
vector<ll> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	v = vector<ll>(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	while(q--){
		int t;
		cin>>t;
		auto arr = v;
		int p = t;
		for(auto &i:arr)if(p == 0)break;else i += p--;
		if(p&1)arr.back() -= p+1,p++;
		p >>= 1;
		ll l = -1e9,r = *min_element(arr.begin(),arr.end());
		while(l != r){
			ll mid = (l+r+1)>>1;
			ll cnt = 0;
			for(auto &i:arr)cnt += i-mid;
			//cout<<mid<<":"<<cnt<<endl;
			if(cnt>=p)l = mid;
			else r = mid-1;
		}
		cout<<l<<' ';
		//cout<<endl<<endl;
	}
	return 0;
}
