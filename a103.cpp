#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> dsjset;
int findroot(int now){
	while(dsjset[now] != now){
		dsjset[now] = dsjset[dsjset[now]];
		now = dsjset[now];
	}
	return now;
}
int main(){
	int n;
	cin>>n;
	dsjset = vector<int>(n);
	for(int i = 0;i<n;i++){
		dsjset[i] = i;
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		dsjset[findroot(k)] = findroot(i);
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(dsjset[i] == i)ans++;
	}
	cout<<ans;
}

