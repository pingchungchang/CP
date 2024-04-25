#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define int ll
#define sc second

const int mxn = 1e6+10;
int sh = mxn>>1;
int dsu[mxn],sz[mxn];

int root(int k){
	return dsu[k] == k?k:dsu[k] = root(dsu[k]);
}

ll rev(ll x){
	return sh-(x-sh);
}

void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = sh-n;i<=sh+n;i++)if(i)dsu[i] = i,sz[i] = 1;
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int a,b;
			cin>>a>>b;
			assert(a<=n&&a>=1&&b<=n&&b>=1);
			onion(sh+a,sh+b);
			onion(sh-a,sh-b);
		}
		else{
			int a;
			cin>>a;
			assert(a<=n&&a>=1);
			//for(int i = -n;i<=n;i++)if(i)cout<<i<<":"<<root(sh+i)<<endl;
			if(root(sh+a) != root(sh-a)){
				cout<<"\\\%\'\"\'\"\"\'\'\"\%/\n";
			}
			else cout<<"ck3fg1sc_f1ag{BrineOrzOrzOrz}\n";
		}
	}
	return 0;
}
