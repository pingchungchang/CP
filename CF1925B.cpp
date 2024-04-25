#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


inline bool check(int a,int b,int k){
	if(b*k<=a&&(a-b*k)%k == 0)return true;
	else return false;
}

void solve(){
	int a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i = 1;i*i<=a;i++){
		if(a%i == 0){
			if(check(a,b,i))ans = max(ans,i);
			if(check(a,b,a/i))ans = max(ans,a/i);
		}
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
