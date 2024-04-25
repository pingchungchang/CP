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
	int neg = 0;
	for(auto &i:arr)cin>>i,neg += (i<0);
	if(neg&1)cout<<"0\n";
	else{
		for(auto &i:arr)if(!i){
			cout<<"0\n";
			return;
		}
		cout<<"1\n1 0\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
