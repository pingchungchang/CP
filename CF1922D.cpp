#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
ll a[mxn],d[mxn];
ll n;
set<int> st;

bool over(int p){
	auto lit = st.lower_bound(p),rit = st.upper_bound(p);
	ll s = 0;
	if(lit != st.begin())s += a[*prev(lit)];
	if(rit != st.end())s += a[*rit];
	return s>d[p];
}

void solve(){
	cin>>n;
	st.clear();
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++)cin>>d[i];
	for(int i = 1;i<=n;i++)st.insert(i);
	vector<int> ans,check;
	for(int i = 1;i<=n;i++)check.push_back(i);
	do{
		vector<int> v;
		for(auto &i:check){
			if(over(i))v.push_back(i);
		}
		ans.push_back(v.size());
		check.clear();
		for(auto &i:v)st.erase(i);
		for(auto &i:v){
			auto it = st.upper_bound(i);
			if(it != st.end())check.push_back(*it);
			if(it != st.begin())check.push_back(*prev(it));
		}
		sort(check.begin(),check.end());
		check.resize(unique(check.begin(),check.end())-check.begin());
	}while(!check.empty());
	while(ans.size()<n)ans.push_back(0);
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
