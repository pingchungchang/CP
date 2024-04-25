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
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(auto &i:arr)cin>>i;
	while(m--){
		bool flag = true;
		int tmp[n+1] = {};
		for(int i = 0;i<n;i++){
			tmp[max(0,i-arr[i])]++;
			tmp[min(n,i+arr[i]+1)]--;
		}
		int now = 0;
		for(int i = 0;i<n;i++){
			now += tmp[i];
			arr[i] = now;
		}
		for(auto &i:arr)if(i != n)flag = false;
		if(flag)break;
	}
	for(auto &i:arr)cout<<i<<' ';
	return 0;
}

