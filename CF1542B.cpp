#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll p = 1;
	if(a == 1){
		if((n-1)%b != 0){
			cout<<"NO\n";
		}
		else cout<<"YES\n";
		return;
	}
//	cout<<n<<' '<<a<<' '<<b<<endl;
	while(p<=n){
//		cout<<n<<' '<<p<<'\n';
		if((n-p)%b == 0){
			cout<<"YES\n";
			return;
		}
		p *= a;
	}
	cout<<"NO\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
