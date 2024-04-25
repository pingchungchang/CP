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
	int l = 1,r = n;
	for(int i = 0;i<n;i+=2)arr[i] = l++;
	for(int i = 1;i<n;i+=2)arr[i] = r--;
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
