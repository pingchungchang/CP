#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 3e5+10;
int cnt[mxn];
bitset<mxn> goneto;
int par[mxn];
vector<int> paths[mxn],tree[mxn];
int dep[mxn];
pii req[mxn];
void maketree(int now){
	goneto[now] = true;
	for(auto nxt:paths[now]){
		if(!goneto[nxt]){
//			cout<<now<<','<<nxt<<'\n';
			par[nxt] = now;
			dep[nxt] = dep[now]+1;
			tree[now].push_back(nxt);
			maketree(nxt);
		}
	}
	return;
}
void getpath(int s,int e){
	vector<int> a,b;
	a.push_back(s);
	b.push_back(e);
	while(s != e){
//		cout<<s<<' '<<e<<'\n';
		if(dep[e]>dep[s]){
			b.push_back(e);
			e = par[e];
		}
		else{
			a.push_back(s);
			s = par[s];
		}
	}
	a.push_back(s);
	for(int i = b.size()-1;i>=0;i--)a.push_back(b[i]);
//	a.erase(unique(_all(a)),a.end());
	int pre = -1;
	b.clear();
	for(auto &i:a){
		if(i == pre)continue;
		b.push_back(i);
		pre = i;
	}
	cout<<b.size()<<'\n';
	for(auto &i:b)cout<<i<<' ';
	cout<<'\n';
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>req[i].fs>>req[i].sc;
		cnt[req[i].fs]++,cnt[req[i].sc]++;
	}
	int fail = 0;
	for(int i = 1;i<=n;i++){
		if(cnt[i]&1)fail++;
	}
	if(fail){
		cout<<"NO\n";
		cout<<fail/2<<'\n';
		return 0;
	}
	maketree(1);
	cout<<"YES\n";
	for(int i = 0;i<q;i++){
		getpath(req[i].fs,req[i].sc);
	}
}

