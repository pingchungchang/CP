#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,k;
	cin>>n>>k;
	n -= k-3;
	for(int i= 0;i<k-3;i++)cout<<1<<' ';
	if(n%2 == 1){
		n--;
		cout<<1<<' '<<n/2<<' '<<n/2<<'\n';
	}
	else{
		ll fac = 1;
		while(n%2 == 0&&n>4){
			fac *=2;
			n/=2;
		}
		int a = 1,b = (n-1)/2,c = b;
		if(n == 4){
			b = 2;
		}
		else if(n == 3)a = b = c = 1;
		cout<<a*fac<<' '<<b*fac<<' '<<c*fac<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

