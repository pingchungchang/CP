#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)

const int mxn = 2e5+10;

struct node{
	int cnt[3];
	int tag;
	node(){}
};
node segtree[mxn*4];

node pull(node ls,node rs,int l,int m,int r){
	assert(l<=m&&m<=r);
	node re;
	memset(re.cnt,0,sizeof(re.cnt));re.tag = -1;
	for(int i = 0;i<3;i++)re.cnt[i] += ls.cnt[i];
	for(int i = 0;i<3;i++)re.cnt[i] += rs.cnt[i];
	return re;
}
void push(int now,int l,int r){
	if(segtree[now].tag == -1)return;
	int t = segtree[now].tag;
	segtree[now*2+1].tag = t;
	segtree[now*2+2].tag = t;
	memset(segtree[now*2+1].cnt,0,sizeof(segtree[now*2+1].cnt));
	memset(segtree[now*2+2].cnt,0,sizeof(segtree[now*2+2].cnt));
	segtree[now*2+1].cnt[t] = mid-l+1;
	segtree[now*2+2].cnt[t] = r-mid;
	segtree[now].tag = -1;
	segtree[now] = pull(segtree[now*2+1],segtree[now*2+2],l,mid,r);
	return;
}

void modify(int now,int l,int r,int s,int e,int v){
	if(e<s)return;
	if(l>=s&&e>=r){
		segtree[now].tag = v;
		memset(segtree[now].cnt,0,sizeof(segtree[now].cnt));
		segtree[now].cnt[v] = r-l+1;
		return;
	}
	push(now,l,r);
	if(s<=mid)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now] = pull(segtree[now*2+1],segtree[now*2+2],l,mid,r);
}
node getsum(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	push(now,l,r);
	if(mid>=e)return getsum(now*2+1,l,mid,s,e);
	else if(mid<s)return getsum(now*2+2,mid+1,r,s,e);
	else return pull(getsum(now*2+1,l,mid,s,e),getsum(now*2+2,mid+1,r,s,e),max(l,s),mid,min(r,e));
}
int getans(int now,int l,int r){
	if(l == r)return l;
	push(now,l,r);
	if(segtree[now*2+1].cnt[1])return getans(now*2+1,l,mid);
	else return getans(now*2+2,mid+1,r);
}

void dfs(int now,int l,int r){
	cout<<l<<' '<<r<<":"<<segtree[now].tag<<' ';for(auto &i:segtree[now].cnt)cout<<i<<',';cout<<endl;
	if(l == r)return;
	push(now,l,r);
	dfs(now*2+1,l,mid);
	dfs(now*2+2,mid+1,r);
	return;
}

int n,q,x;
int arr[mxn];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q>>x;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = (arr[i] == x?1:arr[i]>x?2:0);
		modify(0,1,n,i,i,arr[i]);
	}
	while(q--){
		int t,s,e;
		cin>>t>>s>>e;
		auto tmp = getsum(0,1,n,s,e);
		if(t == 1){
			for(int i = 0;i<3;i++){
				modify(0,1,n,s,s+tmp.cnt[i]-1,i);
				s += tmp.cnt[i];
			}
		}
		else{
			for(int i = 2;i>=0;i--){
				modify(0,1,n,s,s+tmp.cnt[i]-1,i);
				s += tmp.cnt[i];
			}
		}
		assert(s == e+1);
	}
	cout<<getans(0,1,n);
}
