#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> v;
void solve(){
	ll n;
	cin>>n;
	if(n>v.size())cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(int i = 0;i<n;i++)cout<<v[i]<<' ';cout<<'\n';
	}
}
int main(){
	io
	int t;
	cin>>t;
	v = {1};
	while(v.back()*3<=1e9)v.push_back(v.back()*3);
	while(t--)solve();
}

