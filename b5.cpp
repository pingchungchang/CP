#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<pll> arr(n);
	for(auto &i:arr)cin>>i.fs>>i.sc,i.sc = -i.sc;
	sort(arr.begin(),arr.end());
	for(auto &i:arr)i.sc = -i.sc;
	reverse(arr.begin(),arr.end());
	vector<pll> v = {arr[0]};
	ll r = arr[0].sc;
	for(int i = 1;i<arr.size();i++){
		if(r<=arr[i].sc)continue;
		v.push_back(arr[i]);
		r = arr[i].sc;
	}
	sort(v.begin(),v.end());
	//for(auto &i:v)cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
	r = v[0].sc;
	ll ans = 1;
	for(auto &i:v){
		if(i.fs>r)r = i.sc,ans++;
	}
	//cout<<ans<<endl<<r<<endl;
	cout<<(ans>m?":(":":)");
}
