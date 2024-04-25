#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	deque<int> dq;
	int big = -1,small = 2e9;
	for(auto &i:arr){
		if(dq.empty()){
			dq.push_back(i);
			big = small = i;
			cout<<1;
		}
		else if(dq.back()<=i&&i<=dq[0]){
			cout<<1;
			big = max(big,i);
			small = min(small,i);
			dq.push_back(i);
		}
		else if((i>=big||i<=small)&&dq.back() == big&&dq[0] == small){
			dq.push_back(i);
			big = max(big,i);small = min(small,i);
			cout<<1;
		}
		else cout<<0;
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
