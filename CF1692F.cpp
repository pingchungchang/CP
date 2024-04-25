#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	int one[10] = {};
	int two[10] = {};
	int three[10] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		k %= 10;
		for(int j = 0;j<=9;j++){
			three[(j+k)%10] += two[j];
		}
		for(int j = 0;j<=9;j++){
			two[(j+k)%10] += one[j];
		}
		one[k]++;
//		for(auto j:one)cout<<j;cout<<endl;
//		for(auto j:two)cout<<j;cout<<endl;
//		for(auto j:three)cout<<j;cout<<endl;cout<<endl;
	}
	if(three[3]!=0){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

