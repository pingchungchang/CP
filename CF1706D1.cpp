#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


int arr[3003];
vector<vector<int>> fac(3003);
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	vector<pii> v;
	for(int i = 1;i<=n;i++){
		for(auto j:fac[arr[i]]){
			if(j<arr[i]/k)break;
			v.push_back(make_pair(j,i));
		}
	}
	sort(v.begin(),v.end());
//	for(auto i:v)cout<<i.fs<<' '<<i.sc<<',';cout<<'\n';
	vector<int> cnt(n+1,0);
	int total = 0;
	int l = 0,r = 0;
	int ans = INT_MAX;
	int m = v.size();
	while(l<m){
		while((r != m)&&total != n){
			cnt[v[r].sc]++;
			if(cnt[v[r].sc] == 1)total++;
			r++;
		}
		if(total == n)ans = min(ans,v[r-1].fs-v[l].fs);
		
//		cout<<l<<' '<<r<<'\n';
//		for(int i = 1;i<=n;i++)cout<<cnt[i]<<' ';cout<<'\n';
		cnt[v[l].sc]--;
		if(cnt[v[l].sc] == 0)total--;
		l++;
	}
	cout<<ans<<'\n';
//	cout<<'\n';
	return;
}
int main(){
	io
	for(int i = 0;i<=3000;i++){
		for(int j = 1;j<=i;j++)if(fac[i].empty()||fac[i].back() != i/j)fac[i].push_back(i/j);
		sort(fac[i].rbegin(),fac[i].rend());
	}
	int t;
	cin>>t;
	while(t--)solve();
}
