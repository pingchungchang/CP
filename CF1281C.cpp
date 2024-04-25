#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;

void solve(){
	ll x;
	string s;
	cin>>x>>s;
	ll total = 0;
	ll lsum = 0,rlen = s.size();
	for(ll i = 1;i<=x;i++){
		//cout<<i<<":"<<lsum<<','<<rlen<<' '<<total<<":"<<s<<endl;
		if(s.size()<x){
			lsum = s[i-1]-'0',rlen = 1LL*(s.size()-i)*lsum;
			rlen%=mod;
			total = i+rlen;total = (total>=mod?total-mod:total);
			string ts = s.substr(i,s.size()-i);
			for(int j = 1;j<lsum;j++){
				s += ts;
			}
		}
		else{
			lsum = s[i-1]-'0';
			rlen = (rlen?rlen-1:rlen+mod-1);
			rlen = rlen*lsum%mod;
			total = i+rlen;total = (total>=mod?total-mod:total);
		}
	}
	cout<<total<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
