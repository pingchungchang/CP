#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int x,y,z;
	cin>>x>>y>>z;
	int arr[] = {x,y,z};
	sort(arr,arr+3);
	int cc = 0;
	for(auto &i:arr)if(i == arr[2])cc++;
	if(cc < 2){
		cout<<"NO\n";
		return;
	}
	if(x != y&&y != z&&x != z){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	if(x == y){
		cout<<x<<' '<<1<<' '<<z<<'\n';
	}
	else if(y == z){
		cout<<x<<' '<<1<<' '<<z<<'\n';
	}
	else{
		cout<<y<<' '<<x<<' '<<1<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
