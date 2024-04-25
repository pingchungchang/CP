#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> v[n];
	ll sum = 0;
	vector<int> small;
	for(int i= 0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int tmp;
			cin>>tmp;
			v[i].push_back(tmp);
		}
		sort(v[i].rbegin(),v[i].rend());
		small.push_back(v[i].back());
		v[i].pop_back();
	}
	sort(small.begin(),small.end());
	ll mn = 1e18;
	for(auto &i:v){
		if(i.empty()){
			i.push_back(small.back());
			small.pop_back();
		}
	}
	if(small.empty()){
		for(auto &i:v)sum += i.back();
		cout<<sum<<'\n';
		return;
	}
	for(auto &i:v){
		mn = min(mn,i.back());
		sum += i.back();
	}
	cout<<sum-mn+min(mn,small[0])<<'\n';
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
