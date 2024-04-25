#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int k;
	cin>>k;
	for(int i = 2;i*i<=k;i++){
		if(k%i == 0){
			cout<<"N\n";
			return;
		}
	}
	cout<<"Y\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
