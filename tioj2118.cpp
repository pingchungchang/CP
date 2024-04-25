#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld double
#define ls now*2+1
#define rs now*2+2
#define mid ((l+r)>>1)

const ll mxn = 1e5+10;
ld pw[mxn];
int n,q;
pair<int,ld> segtree[mxn*4];
int punish[5];
int val[5];
int arr[mxn];

void pull(int now){
	assert(segtree[ls].fs>=0&&segtree[rs].fs>=0);
	segtree[now].sc = segtree[ls].sc*pw[segtree[ls].fs]+segtree[rs].sc*pw[segtree[rs].fs];
	return;
}

void changeval(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].sc = val[v];
		return;
	}
	if(mid>=p)changeval(now*2+1,l,mid,p,v);
	else changeval(now*2+2,mid+1,r,p,v);
	pull(now);
}
void modify(int now,int l,int r,int s,int e,int v){
	if(l>r)return;
	if(l>=s&&e>=r){
		segtree[now].fs += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	pull(now);
}

void solve(){
	for(int i = 0;i<=n;i++)arr[i] = 0;
	for(int i= 0;i<=n*4;i++)segtree[i].fs = 0,segtree[i].sc = 0;
	cin>>n>>q>>punish[1]>>punish[2]>>punish[3]>>punish[4];
	for(int i = 1;i<=n;i++)changeval(0,1,n,i,0);
	while(q--){
		int p,v;
		cin>>p>>v;
		for(int i = 0;i<5;i++){
			if(v == val[i]){
				v = i;
				break;
			}
		}
		modify(0,1,n,p+1,p+punish[arr[p]],-1);
		modify(0,1,n,p+1,p+punish[v],1);
		changeval(0,1,n,p,v);
		arr[p] = v;
		ld re = segtree[0].sc*pw[segtree[0].fs];
		cout<<fixed<<setprecision(20)<<re*1e6/320/n<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	val[0] = 320,val[1] = 300,val[2] = 200,val[3] = 100,val[4] = 50;
	pw[0] = 1;
	for(int i = 1;i<mxn;i++)pw[i] = pw[i-1]*0.99;
	int t;cin>>t;
	while(t--)solve();
}
