#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5e5+10;
int segtree[mxn*8];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] = max(segtree[now],v);
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}

int arr[mxn];
int dp[mxn];
int N,D;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>D;
	for(int i = 1;i<=N;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=N;i++){
		dp[i] = getval(0,0,mxn,max(0,arr[i]-D),min(mxn,arr[i]+D))+1;
		modify(0,0,mxn,arr[i],dp[i]);
	}
	cout<<*max_element(dp+1,dp+N+1);
}
