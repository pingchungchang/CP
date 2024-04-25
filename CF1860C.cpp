#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
int bit[mxn];
int n;
void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] = max(bit[p],v);
}
int getval(int k){
	int re = 0;
	for(;k>0;k-= k&-k)re = max(re,bit[k]);
	return re;
}
void init(int p){
	for(;p<mxn;p+=p&-p)bit[p] = 0;
	return;
}

void solve(){
	for(int i = 1;i<=n;i++)init(i);
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(auto &i:arr){
		int v = getval(i);
		if(v == 1)ans++;
		modify(i,v+1);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
