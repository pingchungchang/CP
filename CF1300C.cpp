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
	int cnt[30] = {};
	for(auto &i:arr){
		cin>>i;
		for(int j = 0;j<30;j++){
			if(i&(1<<j))cnt[j]++;
		}
	}
	pii ans = {0,0};
	for(int i = 0;i<n;i++){
		pii tans = {0,i};
		for(int j = 0;j<30;j++){
			if(arr[i]&(1<<j)){
				if(cnt[j] == 1)tans.fs ^= 1<<j;
			}
		}
		ans = max(ans,tans);
	}
	cout<<arr[ans.sc]<<' ';
	for(int i = 0;i<n;i++){
		if(i == ans.sc)continue;
		cout<<arr[i]<<' ';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
