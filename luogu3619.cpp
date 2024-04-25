#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,s;
	cin>>n>>s;
	vector<pii> pos,neg;
	for(int i = 0;i<n;i++){
		pii tmp;
		cin>>tmp.fs>>tmp.sc;
		if(tmp.sc>=0)pos.push_back(tmp);
		else neg.push_back(tmp);
	}
	sort(pos.begin(),pos.end());
	for(auto &i:pos){
		if(i.fs>=s){
			cout<<"-1s\n";
			return;
		}
		s += i.sc;
	}
	for(auto &i:neg)s += i.sc,i.fs += i.sc;
	if(s<=0){
		cout<<"-1s\n";
		return;
	}
	sort(neg.begin(),neg.end());
	for(auto &i:neg){
		if(i.fs>=s){
			cout<<"-1s\n";
			return;
		}
		s -= i.sc;
	}
	cout<<"+1s\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
