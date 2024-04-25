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
	int sum = 0;
	for(auto &i:arr)cin>>i,sum+=i;
	sort(arr+1,arr+n+1);
	int big = *max_element(arr,arr+n);
	if(big>sum-big){
		cout<<"T\n";
		return;
	}
	cout<<(sum&1?"T\n":"HL\n");
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
