#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	ll n,t;
	cin>>n>>t;
	int v[n+1] = {};
	for(int i = 1;i<=n-1;i++){
		cin>>v[i];
		v[i] += i;
	}
	int now = 1;
	while(now != n){
		now = v[now];
		if(now == t){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}

