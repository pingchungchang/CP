#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
ll arr[mxn];
string s;
int n,m;

void solve(){
	for(int i = 0;i<=n;i++)arr[i] = 0;
	cin>>n>>m;
	cin>>s;
	s = "#"+s;
	vector<pii> v;
	for(int i = 0;i<m;i++){
		int tmp;
		cin>>tmp;
		v.push_back({tmp,tmp});
	}
	for(auto &i:v)cin>>i.sc;
	int q;cin>>q;
	while(q--){
		int x;
		cin>>x;
		auto pos = lower_bound(v.begin(),v.end(),make_pair(x,mxn))-v.begin();
		pos--;
		x = min(x,v[pos].fs+v[pos].sc-x);
		arr[x]++;
	}
	for(auto &i:v){
		int p = 0;
		for(int j = i.fs;j<=i.sc+i.fs-j;j++){
			p += arr[j];
			if(p&1){
				swap(s[j],s[i.fs+i.sc-j]);
			}
		}
	}
	s = s.substr(1,n);
	cout<<s<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
