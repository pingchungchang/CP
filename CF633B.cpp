#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll m;
	cin>>m;
	ll C = 0;
	for(ll i = 5;i<1e7;i+=5){
		for(ll j = 5;j<=i;j*=5){
			if(i%j == 0)C++;
		}
		if(C>m){
			cout<<0;
			return 0;
		}
		else if(C == m){
			cout<<"5\n";
			for(int j = 0;j<5;j++)cout<<i+j<<' ';
			return 0;
		}
	}
	return 0;
}
