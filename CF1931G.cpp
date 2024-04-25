#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 4e6+10;
const ll mod = 998244353;
ll fac[mxn],ifac[mxn];

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){return pw(k,mod-2);}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

inline ll C(ll a,ll b){
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
inline ll H(ll a,ll b){
	return C(a+b-1,a-1);
}

void solve(){
	ll arr[4];
	for(auto &i:arr)cin>>i;
	if(abs(arr[0]-arr[1])>1){
		cout<<"0\n";
		return;
	}
	if(arr[0]<arr[1]){
		swap(arr[0],arr[1]);
		swap(arr[2],arr[3]);
	}
	if(arr[0] == arr[1]){
		if(!arr[0]){
			if(arr[2] != 0&&arr[3] != 0)cout<<"0\n";
			else cout<<"1\n";
			return;
		}
		else{
			ll ta = H(arr[0]+1,arr[2])*H(arr[1],arr[3])%mod;
			ll tb = H(arr[1]+1,arr[3])*H(arr[0],arr[2])%mod;
			cout<<mad(ta,tb)<<'\n';
		}
	}
	else{
		cout<<H(arr[0],arr[2])*H(arr[0],arr[3])%mod<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fac[0] = ifac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ifac[mxn-1] = inv(fac[mxn-1]);
	for(int i = mxn-2;i>=0;i--)ifac[i] = ifac[i+1]*(i+1)%mod;
	int t;cin>>t;
	while(t--)solve();
}
