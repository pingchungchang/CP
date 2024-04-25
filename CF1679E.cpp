#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 	998244353;
const ll mxn = 1010;
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
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

string s,ts;
int n,q;
const int bit = 17;
ll dp[18][1<<17];

inline void SOS(ll arr[]){
	for(int i = 0;i<bit;i++){
		for(int j = 0;j<(1<<bit);j++){
			if(j&(1<<i))arr[j] = mad(arr[j],arr[j^(1<<i)]);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>ts;
	for(auto &i:ts)s += i,s += '#';
	int Q = 0;
	for(auto &i:ts)Q += (i == '?');

	for(int i = 0;i<s.size();i++){
		int l = i,r = i;
		int mask = 0,lock = 0;
		while(l>=0&&r<s.size()){
			if(s[l] == '#'){
				l--,r++;
				continue;
			}
			if(s[l] == s[r]&&s[l] != '?'){
				for(int j = __builtin_popcount(mask);j<=bit;j++)dp[j][mask] = mad(dp[j][mask],pw(j,Q-lock));
			}
			else if(s[l] == '?'&&s[r] == '?'){
				int C = (l != r);
				assert(Q-C-lock>=0);
				for(int j = __builtin_popcount(mask);j<=bit;j++)dp[j][mask] = mad(dp[j][mask],pw(j,Q-C-lock));
				lock += C;
			}
			else if(s[l] == '?'||s[r] == '?'){
				if(s[l] != '?')mask = mask|(1<<(s[l]-'a'));
				if(s[r] != '?')mask = mask|(1<<(s[r]-'a'));
				for(int j = __builtin_popcount(mask);j<=bit;j++)dp[j][mask] = mad(dp[j][mask],pw(j,Q-lock-1));
				lock++;
			}
			else break;
			l--,r++;
		}
	}

	for(int i = 1;i<=bit;i++)SOS(dp[i]);
	//for(int i = 0;i<bit;i++)cout<<dp[1][1<<i]<<' ';cout<<endl;
	cin>>q;
	while(q--){
		int mask = 0;
		cin>>ts;
		for(auto &i:ts)mask |= 1<<(i-'a');
		cout<<dp[__builtin_popcount(mask)][mask]<<'\n';
	}
	return 0;
}
