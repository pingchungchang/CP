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
	pii arr[n];
	for(auto &i:arr){
		cin>>i.sc>>i.fs;
	}
	sort(arr,arr+n);
	int now = 0;
	for(auto &i:arr){
		if(now+i.sc>i.fs){
			cout<<"unschedulable\n";
			return;
		}
		now += i.sc;
	}
	cout<<"schedulable\n";
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
