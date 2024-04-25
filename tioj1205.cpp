#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const ll add = 1e9;
void norm(pair<ll,ll> &dir){
	if(dir.first == 0){
		dir.second =1;
		return;
	}
	else if(dir.second == 0){
		dir.first =1;
		return;
	}
	ll a = abs(dir.first);
	ll b = abs(dir.second);
	if(a<b)swap(a,b);
	while(b != 0){
		a -= (a/b)*b;
		swap(a,b);
	}
	dir.first /= a;
	dir.second /= a;
	if(dir.first<0){
		dir.first = -dir.first;
		dir.second = -dir.second;
	}
	return;
}
void solve(){
	vector<pair<ll,ll>> v(n);
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v[i] = make_pair(a,b);
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		map<ll,int> m;
		for(int j = 0;j<n;j++){
			if(j == i)continue;
			pair<ll,ll> dir = make_pair(v[i].first-v[j].first,v[i].second-v[j].second);
			norm(dir);
			pair<ll,ll> pp = make_pair(dir.second,-dir.first);
			norm(pp);
			if(m.count(pp.first*add+pp.second)!= 0){
				ans += m[pp.first*add+pp.second];
//				cout<<endl<<i<<' '<<j<<endl<<endl;
			}
			if(m.count(dir.first*add+dir.second) == 0)m[dir.first*add+dir.second] = 1;
			else m[dir.first*add+dir.second]++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		if(n == 0)return 0;
		solve();
	}
}
