#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e5+10;
int bit[mxn];
int n,k;

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}

int getval(int k){
	int re = 0;
	for(;k>0;k-= k&-k)re += bit[k];
	return re;
}

void solve(){
	for(int i = 1;i<=k*2+1;i++)modify(i,-getval(i));
	cin>>n>>k;
	int arr[n];
	int shift = 0;
	for(auto &i:arr){
		cin>>i;
		if(i>k)i = -1,shift++;
	}
	for(int i = 0;i<n/2;i++){
		if(arr[i] == -1&&arr[n-1-i] == -1)continue;
		modify(1,2);
		modify(min(arr[i],arr[n-1-i])+1,-1);
		modify(arr[i]+arr[n-1-i],-1);
		modify(arr[i]+arr[n-1-i]+1,1);
		modify(max(arr[i],arr[n-1-i])+k+1,1);
	}
	int ans = n;
	for(int i = 1;i<=k*2;i++){
		//cout<<i<<":"<<getval(i)<<',';
		ans = min(ans,getval(i));
	}
	cout<<ans+shift<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
