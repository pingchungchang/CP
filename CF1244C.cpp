#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,p,d,w;
	cin>>n>>p>>w>>d;
	for(ll i = 0;i<=min(max(d,w),n);i++){
		ll tmp = p-d*i;
		if(tmp<0)continue;
		if(tmp%w == 0){
			ll sum = tmp/w+i;
			if(sum>n)continue;
			cout<<tmp/w<<' '<<i<<' '<<n-sum;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}
