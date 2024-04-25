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
	while(n%2 == 0)n>>=1;
	while(n%3 == 0)n/=3;
	if(n == 1)cout<<"Yes";
	else cout<<"No";
}
