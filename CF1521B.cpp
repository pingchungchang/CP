#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	pii sm = make_pair(INT_MAX,-1);
	for(int i = 0;i<n;i++){
		sm = min(sm,make_pair(v[i],i));
	}
	vector<vector<int>> ans;
	for(int i = sm.sc+1;i<n;i++){
		if(v[i-1] == sm.fs){
			ans.push_back({sm.sc+1,i+1,sm.fs,sm.fs+1});
			v[i] = sm.fs+1;
		}
		else{
			ans.push_back({sm.sc+1,i+1,sm.fs,sm.fs});
			v[i] = sm.fs;
		}
	}
	for(int i = sm.sc-1;i>=0;i--){
		if(v[i+1] == sm.fs){
			ans.push_back({i+1,sm.sc+1,sm.fs+1,sm.fs});
			v[i] = sm.fs+1;
		}
		else{
			v[i] = sm.fs;
			ans.push_back({i+1,sm.sc+1,sm.fs,sm.fs});
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		for(auto j:i)cout<<j<<' ';cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

