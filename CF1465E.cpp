#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,tar;
	cin>>n>>tar;
	string s;
	cin>>s;
	tar -= 1ll<<(s.back()-'a');s.pop_back();
	tar += 1ll<<(s.back()-'a');s.pop_back();
	tar = abs(tar);

	ll cnt[64];
	memset(cnt,0,sizeof(cnt));
	ll sum = 0;
	for(auto &i:s)cnt[i-'a'+1]++,sum += (1ll<<(i-'a'));
	tar = tar+sum;
	for(ll i = 0;i<63;i++){
		if(tar == 0){
			cout<<"YES\n";
			return;
		}
		if((1ll<<i)&tar){
			if(!cnt[i]){
				cout<<"NO\n";
				return;
			}
			cnt[i]--;
			tar -= 1ll<<i;
		}
		cnt[i+1] += cnt[i]/2;
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}
