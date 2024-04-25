#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 3e5+10;

pii segtree[mxn*4];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].fs = segtree[now].sc = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].fs = max(segtree[now*2+1].fs,segtree[now*2+2].fs);
	segtree[now].sc = min(segtree[now*2+1].sc,segtree[now*2+2].sc);
	return;
}

pii getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	pii re = {0,mxn};
	if(mid>=s){
		auto tmp = getval(now*2+1,l,mid,s,e);
		re.fs = max(re.fs,tmp.fs);
		re.sc = min(re.sc,tmp.sc);
	}
	if(mid<e){
		auto tmp = getval(now*2+2,mid+1,r,s,e);
		re.fs = max(re.fs,tmp.fs);
		re.sc = min(re.sc,tmp.sc);
	}
	return re;
}

void solve(){
	int n;
	cin>>n;
	vector<int> v;
	int arr[n];
	int pos[n+1] = {};
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		while(v.size()>=2&&1LL*(v.back()-v[v.size()-2])*(arr[i]-v.back())>0)v.pop_back();
		v.push_back(arr[i]);
	}
	int ans = 0;
	n = v.size();
	for(int i = 0;i<n;i++)modify(0,0,n-1,i,v[i]),pos[v[i]] = i;
	int dist[n];
	fill(dist,dist+n,mxn);
	int ptr[2] = {2,1};
	queue<pii> q;
	if(v.size() == 1){
		cout<<"0\n";
		return;
	}
	else if(v.size() == 2){
		cout<<"1\n";
		return;
	}
	int tl = pos[*max_element(v.begin(),v.end())],tr = pos[*min_element(v.begin(),v.end())];
	ans = 1;
	if(tl>tr)swap(tl,tr);
	int now = tr;
	while(now != n-1){
		auto re = getval(0,0,n-1,now,n-1);
		if(re.fs == v[now])now = pos[re.sc];
		else now = pos[re.fs];
		ans++;
	}
	now = tl;
	while(now != 0){
		auto re = getval(0,0,n-1,0,now);
		if(re.fs == v[now])now = pos[re.sc];
		else now = pos[re.fs];
		ans++;
	}
	cout<<ans<<'\n';
	return;
	/*
	for(auto &i:v)cout<<i<<',';cout<<'\n';
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			auto tmp = getval(0,0,n-1,i,j);
			cout<<i<<' '<<j<<":"<<tmp.fs<<' '<<tmp.sc<<endl;
		}
	}

   */
	cout<<dist[n-1]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
