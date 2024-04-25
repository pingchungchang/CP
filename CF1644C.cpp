#include <bits/stdc++.h>
using namespace std;

vector<int> segtree;

void maketree(int pos,int val,int now,int l,int r){
	if(l == r){
		segtree[now] = val;
		return;
	}
	int mid = (l+r)/2;
	if(mid>=pos)maketree(pos,val,now*2+1,l,mid);
	else maketree(pos,val,now*2+2,mid+1,r);
	segtree[now] = min(segtree[now*2+1],segtree[now*2+2]);
}
int getval(int s,int e,int now,int l,int r){
	if(l == s&&e == r)return segtree[now];
	int mid = (l+r)/2;
	if(mid>=e)return getval(s,e,now*2+1,l,mid);
	else if(mid<s)return getval(s,e,now*2+2,mid+1,r);
	else return min(getval(s,mid,now*2+1,l,mid),getval(mid+1,e,now*2+2,mid+1,r));
}
void solve(){
	int n,x;
	cin>>n>>x;
	segtree = vector<int>((n+1)*4,INT_MAX);
	vector<int> v(n+1,0);
	maketree(0,0,0,0,n);
	for(int i = 1;i<=n;++i){
		cin>>v[i];
		v[i] += v[i-1];
		maketree(i,v[i],0,0,n);
	}
	int ans = INT_MIN;
	for(int i = 0;i<=n;i++){
		for(int j = i;j<=n;j++){
			ans = max(ans,v[j]-getval(0,j-i,0,0,n)+x*i);
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
