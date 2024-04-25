#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	int n;
	while(cin>>n){
		if(n == 0)return 0;
		ll biggest = 0;
		ll ans = 2+n;
		for(int i = 0;i<n;i++){
			ll k;
			cin>>k;
			ans += k-1;
			biggest = max(biggest,k-1);
		}
		ans += biggest;
		cout<<ans<<'\n';
	}
}
