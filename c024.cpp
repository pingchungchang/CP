#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	while(cin>>n){
		if(n<0)return 0;
		cout<<n*(n+1)/2+1<<'\n';
	}
	return 0;
}
