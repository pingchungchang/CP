#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	ll arr[n];
	pll sum[2] = {{INT_MAX,0LL},{INT_MAX,0LL}};
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		sum[i%2] = min(sum[i%2],make_pair(arr[i],1LL*i));
	}
	if(n%2 == 1){
		cout<<"Mike\n";
	}
	else{
		if(sum[0].fs>sum[1].fs){
			cout<<"Mike\n";
		}
		else if(sum[0].fs == sum[1].fs){
			if(sum[0].sc<sum[1].sc){
				cout<<"Joe\n";
			}
			else cout<<"Mike\n";
		}
		else{
			cout<<"Joe\n";
		}
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

