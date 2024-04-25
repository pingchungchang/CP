#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
void solve(){
	ll a,b,x;
	cin>>a>>b>>x;
	if(a<b)swap(a,b);
	while(a>=x&&b != 0){
		if(b>x){
			a %= b;
			swap(a,b);
			continue;
		}
		if(a == x||b == x){
			cout<<"YES\n";
			return;
		}
		if((a-x)%b == 0){
			cout<<"YES\n";
			return;
		}
		else{
			a %= b;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

