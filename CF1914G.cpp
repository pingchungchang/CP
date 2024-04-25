#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int dsu[mxn],sz[mxn];
pii arr[mxn];
int n;
priority_queue<int,vector<int>,greater<int>> pq[mxn];
const ll mod = 998244353;
set<pii> st;
int brr[mxn*2];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	if(pq[a].size()<pq[b].size())swap(pq[a],pq[b]);
	while(!pq[b].empty()){
		pq[a].push(pq[b].top());
		pq[b].pop();
	}
	return;
}

void del(int id){
	id = root(id);
	pq[id].pop();
	if(!pq[id].empty()){
		st.insert({pq[id].top(),id});
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++)arr[i] = {0,0};
	for(int i = 0;i<=n;i++)while(!pq[i].empty())pq[i].pop();
	cin>>n;
	st.clear();
	for(int i = 1;i<=n*2;i++){
		int k;
		cin>>k;
		if(arr[k].fs)arr[k].sc = i;
		else arr[k].fs = i;
		brr[i] = k;
	}
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1;
	sort(arr+1,arr+n+1);
	ll ans1 = 0,ans2 = 0;
	for(int i = 1;i<=n;i++){
		while(!st.empty()&&st.begin()->fs<arr[i].fs){
			del(st.begin()->sc);
			st.erase(*st.begin());
		}
		if(st.empty())ans1++;
		//cout<<arr[i].fs<<' '<<arr[i].sc<<":";for(auto &j:st)cout<<j.fs<<','<<j.sc<<' ';cout<<endl;
		auto rit = st.lower_bound({arr[i].sc,-1});
		for(auto it = st.begin();it != rit;it++){
			onion(it->sc,i);
		}
		if(rit != st.begin())st.erase(st.begin(),rit);
		pq[root(i)].push(arr[i].sc);
		st.insert({pq[root(i)].top(),root(i)});
	}
	ans2 = 1;
	int p = 1;
	while(p<=n){
		ans2 = ans2*sz[root(p)]%mod*2%mod;
		int r = arr[p].sc;
		while(p<=n&&arr[p].fs<r){
			r = max(r,arr[p].sc);
			p++;
		}
	}
	cout<<ans1<<' '<<ans2<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
