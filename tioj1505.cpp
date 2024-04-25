#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<int> v;

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll G = arr[1];
	for(int i = 0;i<n;i++){
		if(i == 1)continue;
		G /= __gcd(G,arr[i]);
	}
	if(G == 1)cout<<"Asssss!!\n";
	else cout<<"zzz...\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
