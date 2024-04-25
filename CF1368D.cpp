#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll re[n];
	memset(re,0,sizeof(re));
	for(int i = 30;i>=0;i--){
		int cnt = 0;
		for(auto &j:arr)if(j&(1<<i))cnt++;
		for(auto &j:re){
			if(!cnt)break;
			cnt--;
			j^= 1<<i;
		}
	}
	ll ans = 0;
	for(auto &i:re)ans += i*i;
	cout<<ans;
}
