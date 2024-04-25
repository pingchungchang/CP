#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 12;
ll N;
pll arr[mxn];

pll extgcd(ll a,ll b,ll c){
	if(!c)return pll(0,0);
	if(c%__gcd(a,b) != 0)return pll(0,0);
	ll G = __gcd(a,b);
	a/=G,b/=G,c/=G;
	array<ll,3> ta = {1ll,0,a};
	array<ll,3> tb = {0,1ll,b};
	if(ta[2]<tb[2])swap(ta,tb);
	while(ta[2] != 1){
		ll coef = ta[2]/tb[2];
		ta[0] -= coef*tb[0];
		ta[1] -= coef*tb[1];
		ta[2] -= coef*tb[2];
		swap(ta,tb);
	}
	return pll(ta[0]*c,tb[0]*c);
}

namespace PCC{
	ll norm(ll k,ll mod){
		if(k>=0)return k%mod;
		else return (k+(abs(k)+mod-1)/mod*mod)%mod;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
	ll pi = 1;
	for(int i = 1;i<=N;i++)pi *= arr[i].fs;
	for(int i = 1;i<=N;i++){
		auto tmp = pi/arr[i].fs;
		//assert(tmp%arr[i].fs != 0);
	}
	ll ans = 0;
	for(int i = 1;i<=N;i++){
		ll inv = PCC::norm(extgcd(pi/arr[i].fs,arr[i].fs,1).fs,arr[i].fs);
		cerr<<pi/arr[i].fs<<','<<arr[i].fs<<":"<<inv<<','<<arr[i].sc<<endl;
		//assert((pi/arr[i].fs)*inv%arr[i].fs == 1);
		ans += arr[i].sc*(pi/arr[i].fs)*PCC::norm(extgcd(pi/arr[i].fs,arr[i].fs,1).fs,arr[i].fs);
	}
	cout<<ans%pi<<endl;
	for(int i = 1;i<=N;i++){
		assert((ans%pi)%arr[i].fs == arr[i].sc);
	}
}
