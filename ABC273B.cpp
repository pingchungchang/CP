#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll n;
	cin>>n;
	int k;
	cin>>k;
	for(int i = 1;i<=k;i++){
		n = round((ld)n/pow(10,i))*pow(10,i);
	}
	cout<<n;
}

