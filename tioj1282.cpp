#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second
#define mid ((l+r)>>1)

const ll mxn = 1e5+10;
pll seg1[mxn*4];
ll seg2[mxn*4],arr[mxn];

void modify1(int now,int l,int r,int s,int e,ll v){
	if(l>=s&&e>=r){
		seg1[now].fs += v;
		return;
	}
	if(mid>=s)modify1(now*2+1,l,mid,s,e,v);
	if(mid<e)modify1(now*2+2,mid+1,r,s,e,v);
	seg1[now].sc = min(seg1[now*2+1].fs+seg1[now*2+1].sc,seg1[now*2+2].fs+seg1[now*2+2].sc);
	return;
}
ll getval1(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return seg1[now].fs+seg1[now].sc;
	if(mid>=e)return seg1[now].fs+getval1(now*2+1,l,mid,s,e);
	else if(mid<s)return seg1[now].fs+getval1(now*2+2,mid+1,r,s,e);
	else return seg1[now].fs+min(getval1(now*2+1,l,mid,s,e),getval1(now*2+2,mid+1,r,s,e));
}

void modify2(int now,int l,int r,int p,ll v){
	if(l == r){
		seg2[now] = v;
		return;
	}
	if(mid>=p)modify2(now*2+1,l,mid,p,v);
	else modify2(now*2+2,mid+1,r,p,v);
	seg2[now] = __gcd(seg2[now*2+1],seg2[now*2+2]);
	return;
}
ll getval2(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return seg2[now];
	if(mid>=e)return getval2(now*2+1,l,mid,s,e);
	else if(mid<s)return getval2(now*2+2,mid+1,r,s,e);
	else return __gcd(getval2(now*2+1,l,mid,s,e),getval2(now*2+2,mid+1,r,s,e));
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		modify1(0,0,n+1,i,i,arr[i]);
		modify2(0,0,n+1,i,abs(arr[i]-arr[i-1]));
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll l,r,k;
			cin>>l>>r>>k;
			modify1(0,0,n+1,l,r,k);
			int a = getval1(0,0,n+1,l-1,l-1),b = getval1(0,0,n+1,l,l);
			modify2(0,0,n+1,l,abs(a-b));
			a = getval1(0,0,n+1,r,r),b = getval1(0,0,n+1,r+1,r+1);
			modify2(0,0,n+1,r+1,abs(a-b));
		}
		else{
			int l,r;
			cin>>l>>r;
			if(l == r){
				cout<<getval1(0,0,n+1,l,l)<<'\n';
				continue;
			}
			ll C = getval2(0,0,n+1,l+1,r);
			cout<<__gcd(C,getval1(0,0,n+1,l,r))<<'\n';
		}
		/*
		for(int i = 1;i<=n;i++){
			cout<<getval1(0,0,n+1,i,i)<<',';
		}
		cout<<endl;
	   */
	}
	return 0;
}
