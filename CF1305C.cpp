#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,m,mod;
inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re =re*a%m;
		b>>=1;
		a = a*a%m;
	}
	return re;
}
inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	mod = m;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
	}
	sort(arr,arr+n);
	for(auto &i:arr)i%=m;
	int cnt[m];
	memset(cnt,0,sizeof(cnt));
	ll ans = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			ans = ans*pw(mad(j,arr[i]),cnt[j])%m;
		}
		if(cnt[(m-arr[i])%m]){
			cout<<"0\n";
			return 0;
		}
		if(!arr[i])cnt[0]++;
		else cnt[m-arr[i]]++;
	}
	cout<<ans;
}
