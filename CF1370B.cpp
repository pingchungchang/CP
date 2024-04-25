#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	vector<int> ev,od;
	for(int i = 1;i<=n*2;i++){
		int a;
		cin>>a;
		if(a&1)od.push_back(i);
		else ev.push_back(i);
	}
	vector<pii> ans;
	while(ev.size()+od.size()>2&&ev.size()>=2){
		ans.push_back({ev.back(),0});
		ev.pop_back();
		ans.back().sc = ev.back();
		ev.pop_back();
	}
	while(od.size()+ev.size()>2){
		ans.push_back({od.back(),0});
		od.pop_back();
		ans.back().sc = od.back();
		od.pop_back();
	}
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
