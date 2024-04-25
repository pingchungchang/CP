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
	if(n<100){
		for(int i = 1;i<n;i++){
			for(int j = i+1;j+i<n;j++){
				int k = n-i-j;
				if(k<=j)continue;
				if(i%3 != 0&&j %3 != 0&&k %3 != 0){
					cout<<"YES\n";
					cout<<i<<' '<<j<<' '<<k<<'\n';
					return;
				}
			}
		}
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	if(n%3 != 0)cout<<1<<' '<<2<<' '<<n-3<<'\n';
	else cout<<1<<' '<<4<<' '<<n-5<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
