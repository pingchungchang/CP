#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	ll n,x,y;
	cin>>n>>x>>y;
	ll arr[n+1];
	for(int i = 0;i<n;i++)cin>>arr[i];
	arr[n] = 1e18;
	sort(arr,arr+n+1);
	ll xx = x;
	auto p = upper_bound(arr,arr+n+1,x)-arr;
	for(int i = 0;i<n;i++){
		if(xx>=arr[i])xx++;
		else xx--;
		if(xx == y){
			cout<<i+1<<'\n';
			return;
		}
	}
	if(xx<=x){
		cout<<-1<<'\n';
		return;
	}
	ll ans = 0;
	//for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	while(true){
		while(arr[p]<y&&x+p>=arr[p])p++;
		//cout<<x<<','<<p<<','<<ans<<'\n';
		if(y-x<=p){
			ans += y-x;
			break;
		}
		else if(arr[p]>=y){
			ll d = p-(n-p);
			d = (y-x-p+d-1)/d;
			ans += d*n;
			d *= p-(n-p);
			x += d;
			continue;
		}
		if(arr[p]-x>=p){
			ll dif = arr[p]-(x+p);
			ll d = p-(n-p);
			d = (dif+d-1)/d;
			ans += d*n;
			d *= p-(n-p);
			x += d;
		}
	}
	cout<<ans<<'\n';
}
//p<n->2p-n<p

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
