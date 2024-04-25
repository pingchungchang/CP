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
	int arr[n] = {};
	for(int i = 0;i<n;i++)arr[i] = i+1;
	auto check = [&](){
		for(int i = 0;i<n;i++){
			int s = 0;
			for(int j = i;j<n;j++){
				s |= arr[j];
				if(s<j-i+1)return false;
			}
		}
		return true;
	};
	while(!check()){
		random_shuffle(arr,arr+n);
	}
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
