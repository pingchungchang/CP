#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;

void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n],brr[m],lp[m],rp[m] = {};
	memset(rp,-1,sizeof(rp));
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	int pt = m-1;
	for(int i = n-1;i>=0;i--){
		if(pt != m-1&&brr[pt+1]>arr[i])rp[pt] = max(rp[pt],i);
		if(pt>=0&&brr[pt] == arr[i]){
			lp[pt] = i;
			if(rp[pt] == -1)rp[pt] = i;
			pt--;
		}
		if(pt>=0&&brr[pt]>arr[i]){
			cout<<"0\n";
			return;
		}
	}
	if(pt != -1){
		cout<<"0\n";
		return;
	}
	for(int i = 0;i<lp[i];i++){
		if(arr[i]<brr[0]){
			cout<<"0\n";
			return;
		}
	}
	ll ans = 1;
	for(int i = 0;i<m-1;i++){
		ans = ans*(lp[i+1]-lp[i]-(rp[i]-lp[i]))%mod;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
