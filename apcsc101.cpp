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
	io
	ll k;
	cin>>k;
	for(int i = k+1;i<=1e7;i++){
		if(i*k%(i-k) == 0&&(i*k)/(i-k) >=i)cout<<i<<' '<<i*k/(i-k)<<'\n';
	}
	return 0;
}

