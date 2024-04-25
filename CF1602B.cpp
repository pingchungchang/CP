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
	map<vector<int>,int> st;
	map<int,vector<int>> mp;
	vector<int> v(n);
	map<int,int> cnt;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		cnt[v[i]]++;
	}
	int c = -1;
	int cy = -1;
	while(st.find(v) == st.end()){
		mp[++c] = v;
		st[v] = c;
		map<int,int> tmp;
		for(auto &i:v){
			i = cnt[i];
			tmp[i]++;
		}
		cnt = tmp;
	}
	cy = st[v];
	int q;
	cin>>q;
	while(q--){
		ll x,k;
		cin>>x>>k;
		if(cy>=k)cout<<mp[k][x-1]<<'\n';
		else{
			k -= cy;
			cout<<mp[k%(mp.size()-cy)+cy][x-1]<<'\n';
		}
	}
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

