#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mod;
int n1 = 'z'-'A'+1;
ll cc[1030][1030];
ll perms(vector<ll> s,int n){
	ll total = 1LL*n;
	ll ans = 1;
	for(ll i:s){
		ans = ans*cc[total][i]%mod;
		total -= i;
	}
	return ans;
}
ll f(string s){
	if(s.size() == 1)return 1LL;
	int n = s.size();
	vector<ll> v('z'-'A'+1,0);
	for(auto i:s)v[i-'A']++;
	ll ans = 0;
	for(int i = 0;i<n1;i++){
		if(v[i] != 0&&i+'A'<s[0]){
			v[i]--;
//			cout<<(char)('A'+i)<<endl<<endl;
			ans = (ans+perms(v,n-1))%mod;
			v[i]++;
		}
		else if(i>=s[0])break;
	}
	ll returns = ans+f(s.substr(1,s.size()-1));
	returns %= mod;
//	cout<<s<<' '<<ans<<'\n';
	return returns;
}
int main(){
	string s;
	cin>>mod>>s;
	memset(cc,0,sizeof(cc));
	cc[0][0] = 1;
	for(ll i = 1;i<=1024;i++){
		for(ll j = 0;j<=i;j++){
			cc[i][j] = cc[i-1][j];
			if(j != 0)cc[i][j] += cc[i-1][j-1];
			cc[i][j]%=mod;
		}
	}
//	cout<<perms(v);
	cout<<(f(s)+mod-1)%mod;
}

