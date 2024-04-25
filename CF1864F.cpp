#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid  ((l+r)>>1)

const int mxn = 1e6+10;

int n,q;
int arr[mxn];
vector<pii> req[mxn];
vector<int> v[mxn];
vector<int> add[mxn];
bitset<mxn> hi;
int ans[mxn];

namespace BIT{
	int bit[mxn];
	void modify(int p,int v){
		for(;p<mxn;p+=p&-p)bit[p] += v;
		return;
	}
	int getval(int p){
		int re = 0;
		for(;p>0;p-= p&-p)re += bit[p];
		return re;
	}
}

namespace SEG{
	int segtree[mxn*4];
	void build(int now,int l,int r){
		if(l == r){
			segtree[now] = arr[l];
			return;
		}
		build(now*2+1,l,mid);
		build(now*2+2,mid+1,r);
		segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	}
	void modify(int now,int l,int r,int p,int v){
		if(l == r){
			segtree[now] = v;
			return;
		}
		if(mid>=p)modify(now*2+1,l,mid,p,v);
		else modify(now*2+2,mid+1,r,p,v);
		segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
	}
	int getval(int now,int l,int r,int s,int e){
		if(l>=s&&e>=r)return segtree[now];
		if(mid>=e)return getval(now*2+1,l,mid,s,e);
		else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
		else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
	}
	void dfs(int now,int l,int r){
		cout<<l<<' '<<r<<":"<<segtree[now]<<endl;
		if(l == r)return;
		dfs(now*2+1,l,mid);
		dfs(now*2+2,mid+1,r);
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	for(int i = 1;i<mxn;i++){
		for(int j = 1;j<v[i].size();j++){
			int tmp = SEG::getval(0,1,n,v[i][j-1],v[i][j]);
			if(tmp)add[tmp].push_back(i);
			//cout<<tmp<<','<<i<<endl;
		}
		for(auto &j:v[i])SEG::modify(0,1,n,j,i);
	}

	for(int i = 0;i<q;i++){
		int l,r;
		cin>>l>>r;
		req[l].push_back({r,i});
	}
	for(int i = mxn-1;i>=1;i--){
		for(auto &j:add[i]){
			BIT::modify(j,1);
		}
		if(v[i].size())BIT::modify(i,1);
		for(auto &j:req[i]){
			ans[j.sc] = BIT::getval(j.fs);
		}
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
