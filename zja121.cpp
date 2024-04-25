#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int a,b;

bool isp(int k){
	if(k == 1)return false;
	for(int i = 2;i*i<=k;i++){
		if(k%i == 0)return false;
	}
	return true;
}

void solve(){
	int ans = 0;
	for(int i = a;i<=b;i++){
		if(isp(i))ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>a>>b)solve();
}
