#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 3e5+10;
int dp[mxn];
int arr[mxn];
pii segtree[mxn*4];
vector<int> paths[mxn];
int n;

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = {arr[l],arr[l]};
		return;
	}
	int mid = (l+r)>>1;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now].fs = min(segtree[now*2+1].fs,segtree[now*2+2].fs);
	segtree[now].sc = max(segtree[now*2+1].sc,segtree[now*2+2].sc);
}
int getmin(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now].fs;
	}
	int mid = (l+r)>>1;
	if(mid>=e)return getmin(now*2+1,l,mid,s,e);
	else if(s>mid)return getmin(now*2+2,mid+1,r,s,e);
	else return min(getmin(now*2+1,l,mid,s,e),getmin(now*2+2,mid+1,r,s,e));
}
int getmax(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now].sc;
	}
	int mid = (l+r)>>1;
	if(mid>=e)return getmax(now*2+1,l,mid,s,e);
	else if(s>mid)return getmax(now*2+2,mid+1,r,s,e);
	else return max(getmax(now*2+1,l,mid,s,e),getmax(now*2+2,mid+1,r,s,e));
}

bool cbig(int s,int e){
	if(s+1 == e)return true;
	return min(arr[s],arr[e])>getmax(0,1,n,s+1,e-1);
}
bool csmall(int s,int e){
	if(s+1 == e)return true;
	return max(arr[s],arr[e])<getmin(0,1,n,s+1,e-1);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<pii> all;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		all.push_back({arr[i],i});
	}
	build(0,1,n);
	set<int> st;
	sort(all.begin(),all.end());
	for(auto &i:all){
		auto it = st.insert(i.sc).fs;
		if(it != st.begin()&&csmall(*prev(it),*it)){
			paths[*prev(it)].push_back(*it);
		}
		if(*it != *st.rbegin()&&csmall(*it,*next(it))){
			paths[*it].push_back(*next(it));
		}
	}
	//for(int i = 1;i<=n;i++)cout<<getmax(0,1,n,3,3)<<' ';return 0;
	sort(all.rbegin(),all.rend());
	st.clear();
	for(auto &i:all){
		auto it = st.insert(i.sc).fs;
		if(it != st.begin()&&cbig(*prev(it),*it)){
			paths[*prev(it)].push_back(*it);
		}
		if(*it != *st.rbegin()&&cbig(*it,*next(it))){
			paths[*it].push_back(*next(it));
		}
	}
	fill(dp,dp+mxn,mxn);
	dp[0] = dp[1] = 0;
	for(int i = 1;i<=n;i++){
		for(auto &j:paths[i]){
			//cout<<i<<":"<<j<<'\n';
			dp[j] = min(dp[j],dp[i]+1);
		}
	}
	cout<<dp[n];
}
