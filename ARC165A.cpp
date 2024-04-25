#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n;
	cin>>n;
	map<int,int> fac;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i= 2;i*i<=n;i++){
			if(n%i == 0){
				flag = true;
				n/=i;
				fac[i]++;
				break;
			}
		}
	}
	if(n != 1)fac[n]++;
	if(fac.size() == 1)cout<<"No\n";
	else cout<<"Yes\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
