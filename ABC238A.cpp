#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n;
	cin>>n;
	if(n>=7)cout<<"Yes";
	else if((1<<n)>n*n)cout<<"Yes";
	else cout<<"No";	
}

