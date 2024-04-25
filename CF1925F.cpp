#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mod = 999999893;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a+=b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

void solve(){
	ll N;
	cin>>N;
	pll S,D;
	if(N&1){
		S.fs = mub(2ll*pw(2,N/2+1)%mod,4);
		S.sc = mub(4ll*pw(2,N/2)%mod,2);
		D = make_pair(0ll,2);
	}
	else{
		S.fs = mub(4ll*pw(2,N/2)%mod,4);
		S.sc = mub(2ll*pw(2,N/2)%mod,2);
		D = make_pair(0ll,2);
	}
	pll A = make_pair(mub(S.fs,D.fs),mub(S.sc,D.sc));
	pll B = make_pair(mad(S.fs,D.fs),mad(S.sc,D.sc));
	cout<<mub(A.fs*B.sc%mod,A.sc*B.fs%mod)*inv(mub(B.sc*B.sc*2%mod,B.fs*B.fs%mod))%mod<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
