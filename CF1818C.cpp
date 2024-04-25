#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

void solve(){
	int n,q;
	cin>>n>>q;
	int arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i];
	vector<pii> v,vv;
	for(int i = 2;i<=n;i++)if(arr[i]>arr[i-1])vv.push_back({i-1,i});
	for(auto &i:vv){
		if(v.empty()||v.back().sc != i.fs)v.push_back(i);
		else v.back().sc++;
	}
	//for(auto &i:v)cout<<i.fs<<' '<<i.sc<<',';cout<<'\n';
	int pref[n+2] = {};
	for(auto &i:v){
		for(int j = i.fs+1;j<=i.sc+1;j++)pref[j]++;
	}
	for(int i = 1;i<=n;i++)pref[i] += pref[i-1];
	//for(auto &i:pref)cout<<i<<' ';cout<<'\n';
	while(q--){
		int a,b;
		cin>>a>>b;
		int re = pref[b]-pref[a]+1;
		auto ta = upper_bound(v.begin(),v.end(),make_pair(a,n+2))-v.begin();
		//auto tb = lower_bound(v.begin(),v.end(),make_pair(b,n+2))-v.begin();
		if(ta == 0||v[ta-1].sc<a)re++;
		cout<<min(re,b-a+1)<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
