#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> allx;
vector<ll> ally;
struct node{
	ll val;
	ll tag;
	node(){
		val = 0;
		tag = 0;
	}
};

void changeval(ll val,ll s,ll e,ll now,ll l,ll r){
	if(l == s&&e == r){
		segtree[now].tag += val;
	}
}
vector<node> segtree;
void solve(){
	ll n;
	cin>>n;
	vector<vector<ll>> req;
	string s;
	cin>>s;
	int special = 0;
	pll suf[n];
	memset(suf,make_pair(0,0),sizeof(suf));
	for(int i = s.size()-2;i>=0;i--){
		suf[i].fs = suf[i+1].fs;
		suf[i].sc = suf[i+1].sc;
		if(s[i+1] == 'D')suf[i].fs++;
		else suf[i].sc++;
	}
	pair<pll,pll> now = make_pair(make_pair(1,1),make_pair(1,1));
	req.push_back({now.fs.fs,now.fs.sc,now.sc.fs,now.sc.sc});
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'D'){
			now.fs.fs++;
			now.sc.fs = n-suf[i].fs;
		}
		else{
			now.fs.sc++;
			now.sc.sc = n-suf[i].sc;
		}
		req.push_back(now.fs.fs,now.fs.sc,now.sc.fs,now.sc.sc);
	}

	for(auto i:req){
		allx.push_back(i[0]);
		allx.push_back(i[2]+1);
		ally.push_back(i[1]);
		ally.push_back(i[3]+1);
	}
	
	sort(allx.begin(),allx.end());
	allx.erase(unique(allx.begin(),allx.end()));
	sort(ally.begin(),ally.end());
	ally.erase(unique(ally.begin(),ally.end()));
	vector<pll> changes(allx.size());
	for(auto i:req){
		i[0] = lower_bound(allx.begin(),allx.end(),i[0])-allx.begin();
		i[1] = lower_bound(ally.begin(),ally.end(),i[1])-ally.begin();
		i[2] = lower_bound(allx.begin(),allx.end(),i[2]+1)-allx.begin();
		i[3] = lower_bound(ally.begin(),ally.end(),i[3]+1)-ally.begin();
		changes[i[0]].push_back(make_pair(i[1],i[3]));
		changes[i[2]].push_back(make_pair(i[3],i[1]));
	}
	ll ans = 0;
	int ss = ally.size();
	segtree = vector<node>(ss*4,node());
	for(ll i = 0;i<allx.size();i++){
		for(auto j:changes[i]){
			if(j.fs<j.sc)changeval(1,j.fs,j.sc,0,0,ss-1);
			else changeval(-1,j.sc,j.fs,0,0,ss-1);
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

