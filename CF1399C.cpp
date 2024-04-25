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
	int arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(int s = 1;s<55+55;s++){
		map<int,int> mp;
		for(auto &i:arr)mp[i]++;
		int tans = 0;
		for(auto &i:arr){
			if(i == s-i){
				if(mp[i]>1){
					mp[i] -= 2;
					tans++;
				}
			}
			else{
				if(mp.find(s-i) == mp.end())continue;
				if(mp[i]>0&&mp[s-i]>0){
					mp[i]--;
					mp[s-i]--;
					tans++;
				}
			}
		}
		ans = max(ans,tans);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
