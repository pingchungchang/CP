#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll ans = 0;
	ll a,b;
	cin>>a>>b;
	while(a != b){
		if(a<b)swap(a,b);
		if(a%b == 0){
			ans += a/b-1;
			break;
		}
		ans += a/b;
		a %= b;
	}
	cout<<ans;
	return 0;
}
