#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	ll total = 0;
	vector<ll> v(n+2);
	for(auto &i:v){
		cin>>i;
		total += i;
	}
	sort(v.begin(),v.end());
	total -= v.back();
	for(int i = 0;i<n+1;i++){
		if(total-v[i] == v.back()){
			for(int j = 0;j<n+1;j++){
				if(i == j)continue;
				cout<<v[j]<<' ';
			}
			cout<<'\n';
			return;
		}
	}
	if(total != 2*v[n]){
		cout<<"-1\n";
		return;
	}
	for(int i = 0;i<n;i++)cout<<v[i]<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

