#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define int ll
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e9;

void solve(){
	ll n,m,d;
	cin>>n>>m>>d;
	ll arr[m];
	for(int i = 0;i<m;i++){
		cin>>arr[i];
	}
	vector<int> sh;
	if(arr[0] != 1)sh.push_back(1);
	for(auto &i:arr)sh.push_back(i);
	sh.push_back(n+1);
	ll sum = 0;
	for(int i = 1;i<sh.size();i++){
		sum += (sh[i]-sh[i-1]-1)/d;
	}
	sum += sh.size()-1;
	pll ans = {inf,0};
	for(int i = 1;i+1<sh.size();i++){
		ll tsum = sum;
		tsum -= (sh[i]-sh[i-1]-1)/d+(sh[i+1]-sh[i]-1)/d+1;
		tsum += (sh[i+1]-sh[i-1]-1)/d;
		//cout<<i<<":"<<tsum<<endl;
		if(tsum==ans.fs)ans.sc++;
		else if(tsum<ans.fs)ans = {tsum,1};
	}
	if(arr[0] == 1){
		ll tsum = sum;
		if(tsum==ans.fs)ans.sc++;
		else if(tsum<ans.fs)ans = {tsum,1};
	}
	cout<<ans.fs<<' '<<ans.sc<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
