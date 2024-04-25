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
	int n;
	cin>>n;
	int arr[n+1] = {};
	arr[1] = 1;
	for(int i = 2;i<=n;i++)cin>>arr[i];
	int now = n;
	int cnt = 0;
	while(arr[now] != now){
		cnt++;
		now = arr[now];
	}
	cout<<cnt;
}

