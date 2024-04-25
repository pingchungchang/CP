#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n],brr[m];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	int ans =0;
	vector<int> v[n];
	for(int i = 0;i<n;i++){
		for(auto &j:brr)v[i].push_back(arr[i]&j);
		sort(v[i].begin(),v[i].end());
	}
	for(int i = 9;i>=0;i--){
		bool flag = true;
		for(int j = 0;j<n;j++)if(v[j][0]&(1<<i))flag = false;
		if(flag){
			for(int j = 0;j<n;j++){
				while(v[j].back()>=(1<<i))v[j].pop_back();
			}
		}
		else{
			ans ^= 1<<i;
			for(int j = 0;j<n;j++){
				for(auto &k:v[j])k ^= k&(1<<i);
				sort(v[j].begin(),v[j].end());
			}
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
