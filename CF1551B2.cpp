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
	int n,k;
	cin>>n>>k;
	vector<pii> v(n);
	vector<set<int>> used(k+1);
	vector<int> cols(n,0);
	for(int i = 0;i<n;i++){
		cin>>v[i].fs;
		v[i].sc = i;
	}
	sort(v.begin(),v.end());
	int pt = 1;
	for(int i = 0;i<n;i++){
		if(used[pt].find(v[i].fs) == used[pt].end()){
			cols[v[i].sc] = pt;
			used[pt].insert(v[i].fs);
			pt = pt%k+1;
		}
	}
//	for(auto i:used)cout<<i.size()<<',';cout<<'\n';
	int mx = INT_MAX;
	for(int i = 1;i<=k;i++){
		mx = min(mx,(int)used[i].size());
	}
	vector<int> cnt(k+1,0);
	for(int i = 0;i<n;i++){
		if(cols[i] == 0){
			cout<<0<<' ';
			continue;
		}
		if(cnt[cols[i]]<mx){
			cnt[cols[i]]++;
			cout<<cols[i]<<' ';
		}
		else cout<<"0 ";
	}
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

