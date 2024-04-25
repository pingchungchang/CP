#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<vector<int>> segtree;

void changeval(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = vector<int>(41,0);
		segtree[now][v] = 1;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=p)changeval(now*2+1,l,mid,p,v);
	else changeval(now*2+2,mid+1,r,p,v);
	for(int i = 1;i<=40;i++){
		segtree[now][i] = segtree[now*2+1][i]+segtree[now*2+2][i];
	}
	return;
}
vector<int> getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else{
		auto a = getval(now*2+1,l,mid,s,e);
		auto b = getval(now*2+2,mid+1,r,s,e);
		for(int i = 0;i<=40;i++){
			a[i] += b[i];
		}
		return a;
	}
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	segtree = vector<vector<int>>((n+1)*4,vector<int>(41,0));
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		changeval(0,1,n,i,k);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 2){
			int p,v;
			cin>>p>>v;
			changeval(0,1,n,p,v);
		}
		else{
			int s,e;
			cin>>s>>e;
			auto tmp = getval(0,1,n,s,e);
			int cnt = 0;
			for(int i = 1;i<=40;i++)if(tmp[i]) cnt++;
			cout<<cnt<<'\n';
		}
	}
	return 0;
}

