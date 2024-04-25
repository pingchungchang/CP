#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	deque<int> dq;
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
		if(dq.empty())dq.push_back(i);
		else if(dq.front()<i)dq.push_back(i);
		else dq.push_front(i);
	}
	for(auto &i:dq)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
