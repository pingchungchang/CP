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
void solve(){
	int n;
	cin>>n; 
	deque<int> dq;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		dq.push_back(k);
	}
	int ans[n];
	for(int i = 0;i<n;i++){
		if(i&1){
			ans[i] = dq.back();
			dq.pop_back();
		}
		else{
			ans[i] = dq.front();
			dq.pop_front();
		}
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

