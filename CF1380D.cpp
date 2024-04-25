#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int segtree[mxn*4+4];
int arr[mxn+1],pos[mxn+1];

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	return;
}

int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}


main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,x,k,y;
	cin>>n>>m>>x>>k>>y;
	vector<int> brr;
	brr.push_back(0);
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pos[arr[i]] = i;
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		brr.push_back(pos[k]);
		if(brr.back()<brr[brr.size()-2]){
			cout<<"-1";
			return 0;
		}
	}
	brr.push_back(n+1);
	build(0,0,mxn);
	ll ans = 0;
	for(int i = 1;i<brr.size();i++){
		if(brr[i] == brr[i-1]+1)continue;
		ll len = brr[i]-brr[i-1]-1;
		if(len<k&&max(arr[brr[i-1]],arr[brr[i]])<getval(0,0,mxn,brr[i-1]+1,brr[i]-1)){
			cout<<-1;
			return 0;
		}
		if(x<=k*y){
			ans += len/k*x+(len%k)*y;
		}
		else{
			if(max(arr[brr[i-1]],arr[brr[i]])>getval(0,0,mxn,brr[i-1]+1,brr[i]-1))ans += len*y;
			else{
				ans += (len-k)*y+x;
			}
		}
	}
	cout<<ans;
}
