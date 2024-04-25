#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define mid ((l+r)>>1)

const int mxn = 2e5+10;
int segtree[mxn*4][3];
int n;
string s;
int arr[mxn];


void build(int now,int l,int r){
	memset(segtree[now],0,sizeof(segtree[now]));
	if(l == r){
		segtree[now][s[l]-'0'] = arr[l];
		//cout<<l<<' '<<r<<":"<<segtree[now][0]<<' '<<segtree[now][1]<<endl;
		return;
	}
	build(now*2+1,l,mid);build(now*2+2,mid+1,r);
	segtree[now][0] = segtree[now*2+1][0]^segtree[now*2+2][0];
	segtree[now][1] = segtree[now*2+1][1]^segtree[now*2+2][1];
	//cout<<l<<' '<<r<<":"<<segtree[now][0]<<' '<<segtree[now][1]<<endl;
	return;
}

inline void push(int now){
	if(segtree[now][2]&1){
		swap(segtree[now*2+1][0],segtree[now*2+1][1]);
		swap(segtree[now*2+2][0],segtree[now*2+2][1]);
		segtree[now*2+1][2]++;
		segtree[now*2+2][2]++;
	}
	segtree[now][2] = 0;
}

void modify(int now,int l,int r,int s,int e){
	//cout<<now<<' '<<l<<' '<<r<<' '<<s<<' '<<e<<endl;
	if(l>=s&&e>=r){
		swap(segtree[now][0],segtree[now][1]);
		segtree[now][2]++;
		return;
	}
	push(now);
	if(mid>=s)modify(now*2+1,l,mid,s,e);
	if(mid<e)modify(now*2+2,mid+1,r,s,e);
	segtree[now][0] = segtree[now*2+1][0]^segtree[now*2+2][0];
	segtree[now][1] = segtree[now*2+1][1]^segtree[now*2+2][1];
}

void dfs(int now,int l,int r){
	cout<<l<<' '<<r<<":";for(auto &i:segtree[now])cout<<i<<' ';cout<<endl;
	if(l == r)return;
	dfs(now*2+1,l,mid);
	dfs(now*2+2,mid+1,r);
	return;
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	cin>>s;
	s = "#"+s;
	build(0,1,n);
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int l,r;
			cin>>l>>r;
			modify(0,1,n,l,r);
			//dfs(0,1,n);
		}
		else{
			int d;
			cin>>d;
			cout<<segtree[0][d]<<' ';
		}
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
