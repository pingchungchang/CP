#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	vector<int> no[2];
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if((arr[i]&1) != (i&1)){
			no[i&1].push_back(i);
		}
	}
	if(no[0].size() != no[1].size()){
		cout<<"-1\n";
		return;
	}
	cout<<no[0].size()<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
