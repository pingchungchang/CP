#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
const ll mod = 998244353;
ll arr[mxn];
string s;
ll pro = 0;

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


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	cin>>s;
	pro = 1;
	for(int i = 0;i<n-1;i++){
		if(i != 0&&s[i] == '?')arr[i] = i,pro = pro*i%mod;
		else arr[i] = 1;
	}
	cout<<(s[0] == '?'?0:pro)<<'\n';
	while(q--){
		int p;
		char c;
		cin>>p>>c;
		p--;
		if(p != 0)pro = pro*inv(arr[p])%mod;
		s[p] = c;
		if(s[p] == '?')arr[p] = p;
		else arr[p] = 1;
		if(p)pro = pro*arr[p]%mod;
		if(s[0]=='?')cout<<"0\n";
		else cout<<pro<<'\n';
	}
	return 0;
}
