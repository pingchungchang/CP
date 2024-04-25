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
	int sum = 0,z = 0;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
		sum += i;
		if(!i)z++;
	}
	if(z == -sum)cout<<z+1<<'\n';
	else if(sum == 0&&z == 0)cout<<"1\n";
	else if(z != 0)cout<<z<<'\n';
	else cout<<"0\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
