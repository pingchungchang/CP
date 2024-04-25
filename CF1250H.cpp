#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll arr[10];
bool f(int n){
	string s = to_string(n);
	ll tmp[10];
	for(int i = 0;i<10;i++)tmp[i] = arr[i];
	for(auto i:s){
		tmp[i-'0']--;
		if(tmp[i-'0']<0)return false;
	}
	return true;
	
}
void solve(){
	pll tmp = make_pair(INT_MAX,0);
	for(int i = 0;i<10;i++)cin>>arr[i];
	for(int i = 1;i<=1e9;i++){
		if(f(i) == false){
			cout<<i<<endl;
			return;
		}
	}
}
int main(){
	io
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}

