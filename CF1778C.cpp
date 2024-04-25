#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#pragma GCC optimize("O3")

const int mxn = 1e5+10;
string all,a,b,tmp;
int arr[mxn];
bitset<mxn> use;

void solve(){
	all.clear();a.clear();b.clear();
	use.reset();
	ll n,k;
	cin>>n>>k>>a>>b;
	for(auto &i:a)use[i-'a'] = true;
	for(int i = 0;i<26;i++)if(use[i])all+='a'+i;
	for(int i = 0;i<n;i++)arr[i] = a[i];
	for(int i = 0;i<n;i++)arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
	ll ans =0;
	assert(all.size()<=10);
	for(int i = 0;i<(1<<all.size());i++){
		if(__builtin_popcount(i) > k)continue;
		tmp = a;
		for(int j = 0;j<n;j++){
			if(i&(1<<arr[j]))tmp[j] = b[j];
			else tmp[j] = a[j];
		}
		ll len = 0,tans = 0;
		for(int j =0;j<n;j++){
			if(tmp[j] == b[j])len++;
			else{
				tans += len*(len+1)/2;
				len = 0;
			}
		}
		tans += len*(len+1)/2;
		ans = max(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
