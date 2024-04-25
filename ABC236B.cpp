#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll sum = n*(n+1)/2*4;
	for(int i = 0;i<n*4-1;i++){
		ll k;
		cin>>k;
		sum -= k;
	}
	cout<<sum;
}
