#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,k;
	cin>>n>>k;
	for(ll i = n;i>=1;i--){
		if(k%(1LL<<i) == 1LL<<(i-1)){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
