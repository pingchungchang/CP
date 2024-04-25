#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5e5+10;
int segtree[mxn*4+4];

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now] = v;
		return;
	}
	if(segtree[now]){
		segtree[now*2+1] = segtree[now*2+2] = segtree[now];
		segtree[now] = 0;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
}

int getval(int now,int l,int r,int p){
	if(segtree[now])return segtree[now];
	if(l == r)return segtree[now];
	int mid = (l+r)>>1;
	if(mid>=p)return getval(now*2+1,l,mid,p);
	else return getval(now*2+2,mid+1,r,p);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string s;
	int q;
	cin>>n>>s>>q;
	for(int i = 0;i<n;i++){
		if(s[i]>='A'&&s[i]<='Z')modify(0,0,mxn,i,i,1);
		else modify(0,0,mxn,i,i,-1);
	}
	while(q--){
		int t;
		int p;
		char c;
		cin>>t>>p>>c;
		if(t == 1){
			p--;
			if(c>='A'&&c<='Z')modify(0,0,mxn,p,p,1);
			else modify(0,0,mxn,p,p,-1);
			s[p] = c;
		}
		else if(t == 2)modify(0,0,mxn,0,n-1,-1);
		else modify(0,0,mxn,0,n-1,1);
	}
	for(int i = 0;i<n;i++){
		int re = getval(0,0,mxn,i);
		if(re == -1)s[i] = tolower(s[i]);
		else if(re == 1)s[i] = toupper(s[i]);
		cout<<s[i];
	}
	return 0;
}
