#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<ll> all,cnt;
vector<pll> v;
int cp[512];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int C = 0;
	for(char i = 'A';i<='Z';i++)cp[i] = C++;
	for(char i = 'a';i<='z';i++)cp[i] = C++;
	int n,m;
	cin>>m>>n;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ll c = 0;
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		s.erase(unique(s.begin(),s.end()),s.end());
		for(auto &j:s)c |= 1ll<<cp[j];
		ll tmp = ((1ll<<m)-1)^c;
		all.push_back(c);
		v.push_back({c,tmp});
	}
	all.push_back(1ll<<m);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	cnt = vector<ll>(all.size(),0ll);
	for(int i = 0;i<v.size();i++){
		auto pos = lower_bound(all.begin(),all.end(),v[i].sc)-all.begin();
		if(all[pos] == v[i].sc)ans += cnt[pos];
		pos = lower_bound(all.begin(),all.end(),v[i].fs)-all.begin();
		cnt[pos]++;
	}
	cout<<ans;
}
