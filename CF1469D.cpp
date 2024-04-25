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

vector<pii> ans;

void f(int now){
	if(now<=2)return;
	int tmp = sqrt(now);
	while(tmp<(now+tmp-1)/tmp)tmp++;
	for(int j = tmp+1;j<now;j++)ans.push_back({j,now});
	ans.push_back({now,tmp});
	ans.push_back({now,tmp});
	f(tmp);
	return;
}
void solve(){
	ll n;
	cin>>n;
	ans.clear();
	f(n);
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

