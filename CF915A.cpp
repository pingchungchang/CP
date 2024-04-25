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
	int n,k;
	cin>>n>>k;
	int ans = 1e9+10;
	while(n--){
		int tmp;
		cin>>tmp;
		if(k%tmp == 0)ans = min(ans,k/tmp);
	}
	cout<<ans;
}

