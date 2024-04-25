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
	ll n;
	cin>>n;
	vector<map<ll,ll>> v(2);
	int now = 0,pre = 1;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		v[now][k]++;
	}
//	for(auto i:v[now])cout<<i.fs<<' '<<i.sc<<',';cout<<'\n';
	for(int asd = 0;asd<n-1;asd++){
		swap(now,pre);
		v[now].clear();
		ll prev = v[pre].begin()->fs;
		for(auto i:v[pre]){
//			cout<<i.fs<<' '<<pre<<'\n';
			if(i.sc>1){
				v[now][0] += i.sc-1;
			}
			if(i.fs != prev){
				v[now][i.fs-prev]++;
			}
			prev = i.fs;
		}
	}
	cout<<v[now].begin()->fs<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

