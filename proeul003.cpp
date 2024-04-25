#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll ans = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=n;i++){
			if(n%i == 0){
				flag = true;
				n/=i;
				ans = max(ans,i);
			}
		}
	}
	if(n != 1)ans = max(ans,n);
	cout<<ans;
}
