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

const ll mxn = 2e5+10;
map<int,int> cls[mxn];
int dsu[mxn];

int root(int now){
	while(dsu[now] != now){
		dsu[now] = dsu[dsu[now]];
		now = dsu[now];
	}
	return now;
}
void onion(int a,int b){
	int ra = root(a),rb = root(b);
	if(ra == rb)return;
	if(cls[ra].size()<cls[rb].size()){
		swap(ra,rb);
		swap(a,b);
	}
	for(auto &i:cls[rb]){
		cls[ra][i.fs] += i.sc;
	}
	dsu[rb] = ra;
	return;
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		cls[i][k] = 1;
	}
	for(int i = 1;i<mxn;i++)dsu[i] = i;
	while(q--){
		int t;
		cin>>t;
		int a,b;
		cin>>a>>b;
		if(t == 1){
			onion(a,b);
		}
		else{
			int ra = root(a);
			cout<<cls[ra][b]<<'\n';
		}
	}
	return 0;
	
}

