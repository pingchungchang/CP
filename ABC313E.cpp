#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	string s;
	cin>>n>>s;
	for(int i = 1;i<n;i++){
		if(s[i] != '1'&&s[i-1] != '1'){
			cout<<"-1";
			return 0;
		}
	}
	ll t = 1;
	for(int i = n-2;i>=0;i--){
		if(s[i] != '1'){
			t++;
			if(t>=mod)t-=mod;
		}
		else{
			t += t*(s[i+1]-'1')%mod+1;
			if(t>=mod)t-=mod;
		}
	}
	t= t+mod-1;
	cout<<t%mod;
}
