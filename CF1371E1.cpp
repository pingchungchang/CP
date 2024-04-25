#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,p;
	cin>>n>>p;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	vector<int> ans;
	for(ll x = 1;x<4040;x++){
		vector<int> dx;
		ll small = 0;
		for(int j = 0;j<n;j++){
			dx.push_back(max(0,arr[j]-x));
		}
		bool flag = true;
		for(auto &j:dx){
			if(small<j)flag = false;
			if(small-j+1==p)flag = false;
			small++;
		}
		if(flag)ans.push_back(x);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
/*
*/
