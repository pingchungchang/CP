#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll p,q,r,s;
	cin>>p>>q>>r>>s;
	for(ll i = p;i<=q;i++){
		for(ll j = r;j<=s;j++){
			if(abs(i-a) == abs(j-b))cout<<'#';
			else cout<<'.';
		}
		cout<<'\n';
	}
	return 0;
}
