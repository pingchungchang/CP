#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	map<int,int> mp;
	for(auto &i:arr){
		bool flag = true;
		while(flag){
			flag = false;
			for(int j = 2;1ll*j*j<=i;j++){
				if(i%j == 0){
					mp[j]++;
					i/=j;
					flag = true;
					break;
				}
			}
		}
		if(i != 1)mp[i]++;
	}
	for(auto &i:mp){
		if(i.sc%n != 0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
