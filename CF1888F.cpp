#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5e5+10;
set<pii> st;
int n,q;
vector<pii> op[mxn];

bool inside(pii p){
	auto it = st.upper_bound(make_pair(p.sc,mxn));
	if(it == st.begin())return false;
	it--;
	if(it->sc>=p.sc)return true;
	auto it2 = st.upper_bound(make_pair(p.fs,mxn));
}

void solve(){
	for(int i = 0;i<=n+1;i++)op[i].clear();
	st.clear();
	cin>>n>>q;
	st.insert({0,q});
	for(int i = 1;i<=q;i++){
		cin>>req[i].l>>req[i].r>>req[i].val;
		op[req[i].l].push_back({i,req[i].val});
		op[req[i].r+1].push_back({i,-req[i].val});
	}
	for(int i = 1;i<=n;i++){
		vector<pll> v;
		v.push_back({0ll,0ll});
		v.push_back({q+1,0ll});
		for(auto &j:op[i]){
			v.push_back(j);
		}
		sort(v.begin(),v.end());
		map<ll,vector<pii>> mp;
		for(int j = 1;j<v.size();j++)v[j].sc += v[j-1].sc;
		for(int j = 0;j+1<v.size();j++)mp[v[j].sc].push_back({v[j].fs,v[j+1].fs-1});
		int sm = -1;
		for(auto &it:mp){
			if(sm != -1)break;
			for(auto &j:it.sc){
				if(inside(j)){
					sm = it.fs;
					break;
				}
			}
		}
		for(auto &it:mp){
			if(it.fs == sm)continue;
			for(auto &j:it.sc)chop(j);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
