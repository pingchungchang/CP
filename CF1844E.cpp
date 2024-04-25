#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2022;
vector<int> paths[mxn*mxn];
int col[mxn*mxn];
int C = 0;
vector<pii> v;
int n,m,k;

void dfs(int now,int c){
	col[now] = c;
	for(auto nxt:paths[now]){
		if(col[nxt])continue;
		dfs(nxt,c^1);
	}
	return;
}

void solve(){
	for(int i = 0;i<n*m;i++){
		col[i] = 0;
		paths[i].clear();
	}
	v.clear();
	C = 0;
	cin>>n>>m>>k;
	for(int i = 0;i<k;i++){
		pii a,b;
		cin>>a.fs>>a.sc>>b.fs>>b.sc;
		a.fs--,a.sc--,b.fs--,b.sc--;
		pii t1,t2;
		if(a.sc+1 == b.sc)t1 = {a.fs+1,a.sc},t2 = {a.fs,a.sc+1};//{x,y},{x+1,y+1};
		else t1 = {a.fs+1,a.sc},t2 = {a.fs,a.sc-1};//{x,y},{x+1,y-1}
		paths[t1.fs*m+t1.sc].push_back(t2.fs*m+t2.sc);
		paths[t2.fs*m+t2.sc].push_back(t1.fs*m+t1.sc);
		v.push_back({a.fs*m+a.sc,b.fs*m+b.sc});
	}
	for(int i = 0;i<n*m;i++){
		if(!col[i])dfs(i,C+=2);
	}

	cout<<'\n';
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cout<<setw(3)<<col[i*m+j]<<' ';
		}
		cout<<endl;
	}
	/*

   */
	bool flag = true;
	for(auto &i:v){
		if(col[i.fs] == (col[i.sc]^1))flag = false;
	}
	cout<<(flag?"Yes\n":"No\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
