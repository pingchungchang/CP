#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	deque<pii> v;
	string s;
	cin>>s;
	for(int i = 0;i<n;i++){
		if(v.empty()||v.back().fs != s[i]-'A')v.push_back(make_pair(s[i]-'A',1));
		else v.back().sc++;
	}
	if(v[0].fs == 1)v.pop_front();
	if(!v.empty()&&v.back().fs== 0)v.pop_back();
	ll ans = 0;
	for(auto &i:v)ans += i.sc;
	cout<<max(0ll,ans-1)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
