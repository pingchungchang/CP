#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

ll mod;
ll n;
const int mxn =110;
ll arr[mxn][mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = 1ll*re*a%mod;
		b>>=1;
		a = 1ll*a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>mod;
	for(int i = 0;i<n;i++){
		cin>>arr[i][n];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>arr[j][i];
		}
	}
	for(int i = 0;i<n;i++){
		int pt = i;
		while(pt<n&&arr[pt][i] == 0)pt++;
		swap(arr[pt],arr[i]);
		ll tmp = inv(arr[i][i]);
		for(int j = 0;j<=n;j++)arr[i][j] = 1ll*arr[i][j]*tmp%mod;
		for(int j = i+1;j<n;j++){
			ll tmp = arr[j][i];
			for(int k = 0;k<=n;k++){
				arr[j][k] = mub(arr[j][k],1ll*arr[i][k]*tmp%mod);
			}
		}
	}
	for(int i = n-1;i>=0;i--){
		for(int j = i-1;j>=0;j--){
			ll tmp = arr[j][i];
			for(int k = 0;k<=n;k++){
				arr[j][k] = mub(arr[j][k],1ll*arr[i][k]*tmp%mod);
			}
		}
	}
	for(int i = 0;i<n;i++){
		cout<<arr[i][n]<<' ';
	}
	return 0;
}
