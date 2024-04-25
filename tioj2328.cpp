#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 1e9+10;
const ll INF = 4e18;
const ll mxn = 2e5+10;
ll arr[mxn],pref[mxn];
ll dp[mxn];
int root[mxn];
ll n,k,p;
vector<int> st;
deque<int> dq;

struct node{
	int pl,pr,cnt;
	ll sum;
	node(){
		pl = pr = cnt = sum = 0;
	}
};

node segtree[mxn*100];
int ppp = 0;
int newnode(int src = 0){
	ppp++;
	segtree[ppp] = segtree[src];
	return ppp;
}
int modify(int now,int l,int r,int p){
	now = newnode(now);
	if(l == r){
		segtree[now].cnt++;
		segtree[now].sum += l;
		return now;
	}
	int mid = (l+r)>>1;
	if(mid>=p)segtree[now].pl = modify(segtree[now].pl,l,mid,p);
	else segtree[now].pr = modify(segtree[now].pr,mid+1,r,p);
	int rs = segtree[now].pr,ls = segtree[now].pl;
	segtree[now].cnt = segtree[ls].cnt+segtree[rs].cnt;
	segtree[now].sum = segtree[ls].sum+segtree[rs].sum;
	return now;
}
ll getsmall(int s,int e,int l,int r,int num){
	if(l == r){
		return 1ll*num*l;
	}
	int mid = (l+r)>>1;
	if(segtree[segtree[e].pl].cnt-segtree[segtree[s].pl].cnt>=num)return getsmall(segtree[s].pl,segtree[e].pl,l,mid,num);
	else return segtree[segtree[e].pl].sum-segtree[segtree[s].pl].sum
		+getsmall(segtree[s].pr,segtree[e].pr,mid+1,r,num-(segtree[segtree[e].pl].cnt-segtree[segtree[s].pl].cnt));
}

inline ll calc(ll s,ll e){
	ll re = dp[s];
	return re+getsmall(root[s],root[e],0,inf,k)-p;
}
inline ll inter(ll s,ll e){
	int l = e+k,r = n;
	if(l>r)return -1ll;
	while(l < r){
		int mid = (l+r+1)>>1;
		if(calc(s,mid) <= calc(e,mid))l = mid;
		else r = mid-1;
	}
	return l;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>p;
	for(int i = 1;i<=n;i++)cin>>arr[i],pref[i] += pref[i-1]+arr[i];
	dp[0] = 0;
	for(int i = 1;i<=n;i++)root[i] = modify(root[i-1],0,inf,arr[i]);
	dq.push_back(0);
	/*
	cout<<root[n]<<' '<<segtree[n].cnt<<endl;
	cout<<getsmall(0,root[n],0,inf,k)<<endl;return 0;

   */
	for(int i = 1;i<=n;i++){
		dp[i] = -8e18;

		while(!dq.empty()&&i-dq.front()>k)dq.pop_front();
		if(!dq.empty())dp[i] = max(dp[i],pref[i]-p+dp[dq.front()]-pref[dq.front()]);
		while(!dq.empty()&&dp[i]-pref[i]>=dp[dq.back()]-pref[dq.back()])dq.pop_back();
		dq.push_back(i);

		//if(i>=k)cout<<"0 "<<i<<":"<<calc(0,i)<<endl;
		while(st.size()>1&&calc(st.end()[-1],i)<=calc(st.end()[-2],i))st.pop_back();
		if(!st.empty())dp[i] = max(dp[i],calc(st.back(),i));
		if(i-k>=0){
			while(st.size()>1&&inter(st.end()[-2],i-k)<inter(st.end()[-1],i-k))st.pop_back();
			st.push_back(i-k);
		}
	}
	//for(int i = 0;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	cout<<dp[n];
}
