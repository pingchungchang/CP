#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int p = 30;
	for(p=30;p>=0;p--){
		int C = 0;
		for(auto &i:arr){
			if(i&(1<<p))C++;
		}
		if(C&1)break;
	}
	if(p == -1){
		cout<<"DRAW\n";
		return;
	}
	int cnt = 0;
	for(auto &i:arr){
		if(i&(1<<p))cnt++;
	}
	if(cnt == 1){
		cout<<"WIN\n";
		return;
	}
	if(cnt%4 == 3&&(n-cnt)%2 == 1)cout<<"WIN\n";
	else if(cnt%4 == 3)cout<<"LOSE\n";
	else cout<<"WIN\n";
	return;
}

//0 0 0 1 1 1

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
/*
1 0 0 0 0 0

1 1 1 1 1 0

*/
