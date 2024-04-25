#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;

set<int> st;
pii range[mxn];
int dsu[mxn],sz[mxn];
pii arr[mxn];
int n,q;
vector<pair<pii,pii>> op;
bitset<mxn> active,ans;
vector<pair<pii,int>> all[mxn];
int bit[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
inline void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	range[a].fs = min(range[a].fs,range[b].fs);
	range[a].sc = max(range[a].sc,range[b].sc);
	return;
}

inline void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
inline int getval(int p){
	int re = 0;
	for(;p>0;p-= p&-p)re += bit[p];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	st.insert(n+2);
	for(int i = 1;i<=n;i++){
		range[i] = {i,i};
		dsu[i] = i,sz[i] = 1;
	}
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs;arr[i].sc = i;
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++){
		int idx = arr[i].sc;
		active[idx] = true;
		st.insert(idx);
		if(active[idx-1])onion(idx-1,idx);
		if(active[idx+1])onion(idx,idx+1);
		idx = root(idx);
		auto it = st.upper_bound(range[idx].sc);
		op.push_back(make_pair(make_pair(range[idx].fs,range[idx].sc),make_pair(range[idx].sc+1,*it-1)));
	}
	for(auto &i:op){
		all[i.fs.fs].push_back(make_pair(i.sc,1));
		all[i.fs.sc+1].push_back(make_pair(i.sc,-1));
	}
	cin>>q;
	for(int i = 0;i<q;i++){
		int l,r;
		cin>>l>>r;
		all[l].push_back(make_pair(make_pair(i,r),0));
	}
	for(int i = 0;i<=n;i++){
		for(auto &j:all[i]){
			if(j.sc == 0&&getval(j.fs.sc) != 0){
				ans[j.fs.fs] = true;
			}
			else if(j.sc){
				modify(j.fs.fs,j.sc);
				modify(j.fs.sc+1,-j.sc);
			}
		}
	}
	for(int i = 0;i<q;i++)cout<<(ans[i]?"YES\n":"NO\n");
	return 0;
}
