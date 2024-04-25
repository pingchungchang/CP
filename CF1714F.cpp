#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n,d12,d23,d13;
	cin>>n>>d12>>d23>>d13;
	int root = 0;
	if(d12+d13 == d23)root = 1;
	else if(d23+d13 == d12)root = 3;
	else if(d12+d23 == d13)root = 2;
	else root = 4;
	if((d12+d23+d13)%2 != 0||root>n){
		cout<<"NO\n";
		return;
	}
	int tmp = (d12+d23+d13)/2;
	set<int> st;
	int cnt = 4;
	if(cnt == root)cnt++;
	st.erase(root);
	if(d12>tmp||d13>tmp||d23>tmp){
		cout<<"NO\n";return;
	}
	vector<pii> ans;
	int now = root;
	for(int i = 0;i<tmp-d23-1;i++){
		ans.push_back({now,cnt++});
		now = ans.back().sc;
	}
	if(root != 1)ans.push_back({now,1});
	now = root;
	for(int i = 0;i<tmp-d13-1;i++){
		ans.push_back({now,cnt++});
		now = ans.back().sc;
	}
	if(root != 2)ans.push_back({now,2});
	now = root;
	for(int i = 0;i<tmp-d12-1;i++){
		ans.push_back({now,cnt++});
		now = ans.back().sc;
	}
	if(root != 3)ans.push_back({now,3});
	if(cnt-1>n){
		cout<<"NO\n";
		return;
	}
	while(cnt <= n){
		ans.push_back({1,cnt++});
	}
	cout<<"YES\n";
	for(auto i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

