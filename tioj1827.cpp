#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

struct node{
	int pl,pr,cnt;
	node(){}
};
const int mxn = 1e5+10;
int ppp = 0;
node segtree[mxn*60];
int arr[mxn],rt[mxn];
int n,q;

int newnode(int src = 0){
	ppp++;
	segtree[ppp] = segtree[src];
	return ppp;
}
int modify(int now,int l,int r,int p,int v){
	now = newnode(now);
	if(l == r){
		segtree[now].cnt += v;
		return now;
	}
	int mid = (l+r)>>1;
	if(mid>=p)segtree[now].pl = modify(segtree[now].pl,l,mid,p,v);
	else segtree[now].pr = modify(segtree[now].pr,mid+1,r,p,v);
	int ls = segtree[now].pl,rs = segtree[now].pr;
	segtree[now].cnt = segtree[ls].cnt+segtree[rs].cnt;
	return now;
}
int getval(int ta,int tb,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[tb].cnt-segtree[ta].cnt;
	int mid = (l+r)>>1;
	if(mid>=e)return getval(segtree[ta].pl,segtree[tb].pl,l,mid,s,e);
	else if(mid<s)return getval(segtree[ta].pr,segtree[tb].pr,mid+1,r,s,e);
	else return getval(segtree[ta].pl,segtree[tb].pl,l,mid,s,e)+getval(segtree[ta].pr,segtree[tb].pr,mid+1,r,s,e);
}

void solve(){
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i],rt[i] = modify(rt[i-1],1,n,arr[i],1);
	while(q--){
		int p,v;
		cin>>p>>v;
		p++;
		int l = 1,r = n;
		while(l != r){
			int mid = (l+r)>>1;
			int s = max(0,p-mid-1);
			int e = min(n,p+mid);
			if(getval(rt[s],rt[e],1,n,0,mid)>=v)r = mid;
			else l = mid+1;
			//cout<<l<<' '<<mid<<' '<<r<<":"<<s<<','<<e<<":"<<getval(rt[s],rt[e],1,n,0,mid)<<endl;
		}
		cout<<l<<'\n';
	}
	return 0;
}
