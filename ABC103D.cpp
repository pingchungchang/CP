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
	pii arr[m];
	for(auto &i:arr){
		cin>>i.sc>>i.fs;
	}
	sort(arr,arr+m);
	for(auto &i:arr)swap(i.fs,i.sc);
	int r = -1;
	int ans = 0;
	for(auto &i:arr){
		if(r<i.fs){
			ans ++;
			r = i.sc-1;
		}
	}
	cout<<ans;
}

