#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	ll n,w;
	cin>>n>>w;
	ll tar = (w+1)/2;
	vector<ll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	ll total = 0;
	vector<ll> ans;
	for(int i = 0;i<n;i++){
		if(total+v[i]<=w){
			total += v[i];
			ans.push_back(i);
		}
		if(v[i]>=tar&&v[i]<=w){
			cout<<"1\n"<<i+1<<'\n';
			return;
		}
	}
	if(total>=tar){
		cout<<ans.size()<<'\n';
		for(auto i:ans)cout<<i+1<<' ';cout<<'\n';
		return;
	}
	else cout<<"-1\n";
	
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

