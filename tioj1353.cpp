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

const int mxn =1e6+10;
pii segtree[mxn*4+4];
int lpf[mxn],dp[mxn];
void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = {v,-l};
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}
pii getval(int now,int l,int r,int s,int e){
	if(s<=l&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}
int main(){
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i+i;j<mxn;j+=i){
				if(!lpf[j])lpf[j] = i;
			}
		}
	}
//	return 0;
	for(int i = 1;i<mxn;i++){
		if(!lpf[i])dp[i] = 1;
		else dp[i] = dp[i/lpf[i]]+((i/lpf[i])%lpf[i] == 0?0:1);
		modify(0,0,mxn,i,dp[i]);
	}
	int s,e;
	while(cin>>s>>e){
		auto re = getval(0,0,mxn,s,e);
		cout<<-re.sc<<' '<<re.fs<<'\n';
	}
	return 0;
}

