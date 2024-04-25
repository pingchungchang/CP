#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;

struct SEG{
	int pl[mxn*60],pr[mxn*60],cnt[mxn*60];
	int ppp = 0;
	SEG(){}
	int newnode(int src){
		ppp++;
		pl[ppp] = pl[src],pr[ppp] = pr[src],cnt[ppp] = cnt[src];
		return ppp;
	}
	int modify(int now,int l,int r,int p,int v){
		now = newnode(now);
		if(l == r){
			cnt[now]+=v;
			return now;
		}
		int mid = (l+r)>>1;
		if(mid>=p)pl[now] = modify(pl[now],l,mid,p,v);
		else pr[now] = modify(pr[now],mid+1,r,p,v);
		cnt[now] = cnt[pl[now]]+cnt[pr[now]];
		return now;
	}
	int getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r)return cnt[now];
		int mid = (l+r)>>1;
		if(mid>=e)return getval(pl[now],l,mid,s,e);
		else if(mid<s)return getval(pr[now],mid+1,r,s,e);
		else return getval(pl[now],l,mid,s,e)+getval(pr[now],mid+1,r,s,e);
	}
};

SEG seg;
vector<int> v[mxn];
int N,K,Q;
int arr[mxn],rt[mxn],rp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>K;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	for(int i = 1;i<=N;i++){
		if(v[arr[i]].size()>=K)rp[v[arr[i]].end()[-K]] = i;
		v[arr[i]].push_back(i);
		rp[i] = N+1;
	}
	for(int i = 1;i<=N;i++){
		rt[i] = seg.modify(rt[i-1],0,N+1,rp[i],1);
	}
	int ans = 0;
	cin>>Q;
	while(Q--){
		int l,r;
		cin>>l>>r;
		l = (l+ans)%N+1,r = (r+ans)%N+1;
		if(l>r)swap(l,r);
		cout<<(ans = (seg.getval(rt[r],0,N+1,r+1,N+1)-seg.getval(rt[l-1],0,N+1,r+1,N+1)))<<'\n';
	}
}
