#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

struct Q{
	ll id,tp,l,r;
	Q(){}
	Q(ll ii,ll tt,ll s,ll e){
		id = ii,tp = tt,l = s,r = e;
	}
};

const ll mxn = 5e5+10;
const ll inf = 1e9+10;
ll bit[mxn];
vector<ll> all;
map<string,int> mp;
set<pll> st[mxn];
vector<Q> req;

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}

ll getval(int p){
	int re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string s;
		ll a,b;
		cin>>s>>a>>b;
		if(mp.find(s) == mp.end()){
			mp[s] = mp.size()+1;
		}
		all.push_back(a);
		all.push_back(b);
		req.push_back(Q(mp[s],3,a,b));
	}
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int t;
		cin>>t;
		if(t == 1){
			string s;
			int k;
			cin>>s>>k;
			if(mp.find(s) == mp.end()){
				mp[s] = mp.size()+1;
			}
			req.push_back(Q(i+n,1,mp[s],k));
			all.push_back(k);
		}
		else if(t==2){
			int k;
			cin>>k;
			req.push_back(Q(i+n,2,k,k));
			all.push_back(k);
		}
		else{
			string s;
			int a,b;
			cin>>s>>a>>b;
			all.push_back(a);all.push_back(b);
			if(mp.find(s) == mp.end()){
				mp[s] = mp.size()+1;
			}
			req.push_back(Q(mp[s],3,a,b));
		}
	}

	all.push_back(0);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:req){
		if(i.tp == 3){
			i.l = lower_bound(all.begin(),all.end(),i.l)-all.begin();
			i.r = lower_bound(all.begin(),all.end(),i.r)-all.begin();
			st[i.id].insert({i.l,i.r});
			modify(i.l,1);
			modify(i.r+1,-1);
		}
		else if(i.tp == 1){
			i.r = lower_bound(all.begin(),all.end(),i.r)-all.begin();
			auto it = st[i.l].upper_bound(make_pair(i.r,inf));
			if(it != st[i.l].begin()){
				it--;
				if(it->fs <= i.r&&it->sc>=i.r)cout<<"Yes\n";
				else cout<<"No\n";
			}
			else cout<<"No\n";
		}
		else{
			i.l = lower_bound(all.begin(),all.end(),i.l)-all.begin();
			cout<<getval(i.l)<<'\n';
		}
	}
	return 0;
}
