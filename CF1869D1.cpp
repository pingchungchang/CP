#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	ll sum = 0;
	for(auto &i:arr)cin>>i,sum += i;
	if(sum%n != 0){
		cout<<"No\n";
		return;
	}
	sum /= n;
	for(auto &i:arr)i = i-sum;
	vector<ll> need,more;
	ll cnt[32];
	memset(cnt,0,sizeof(cnt));
	for(auto &now:arr){
		bool flag = false;
		for(ll i = 0;i<30;i++){
			for(ll j = 0;j<30;j++){
				if((1LL<<i)-(1LL<<j) == now){
					//cout<<now<<":"<<i<<','<<j<<'\n';
					cnt[i]++;
					cnt[j]--;
					flag = true;
				}
			}
		}
		if(!flag){
			cout<<"NO\n";
			return;
		}
	}
	for(auto &i:cnt){
		if(i){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
