#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,m;
	cin>>n>>m;
	ll cnt[64];memset(cnt,0,sizeof(cnt));
	for(int i = 0;i<m;i++){
		ll k;
		cin>>k;
		ll low = 0;
		for(;low<32&&((1LL<<low)&k) == 0;low++);
		cnt[low]++;
	}
	ll ans = 0;
	for(int i = 0;i<63;i++){
		if(n&(1LL<<i)){
			if(cnt[i] == 0){
				ll car = -1;
				for(car = i+1;car<64&&!cnt[car];car++);
				if(car == 64){
					cout<<"-1\n";
					return;
				}
				ans += car-i;
				for(int j = i+1;j<car;j++)cnt[j]++;
				cnt[car]--;
				cnt[i]+=2;
			}
			cnt[i]--;
		}
		cnt[i+1] += cnt[i]>>1;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
