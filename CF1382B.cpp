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
	bool flag = true;
	int st = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] != 1){
			st = i;
			flag = false;
			break;
		}
	}
	if(flag){
		cout<<(n&1?"First\n":"Second\n");
		return;
	}
	if(st&1)cout<<"Second\n";
	else cout<<"First\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
