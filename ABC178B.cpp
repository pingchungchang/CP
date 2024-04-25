#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll arr[4];
	for(auto &i:arr)cin>>i;
	ll ans = -1e18;
	for(int i = 0;i<2;i++){
		for(int j = 2;j<4;j++){
			ans = max(ans,arr[i]*arr[j]);
		}
	}
	cout<<ans;
}
