#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	int arr[n+1] = {};
	if(n&1){
		int p = n;
		for(int i = 1;i<=n;i+=2){
			arr[i] = p--;
		}
		p = 1;
		for(int i = n-1;i>=1;i -= 2)arr[i] = p++;
	}
	else{
		int p = n/2;
		for(int i = 1;i<=n;i+=2)arr[i] = p--;
		p = n;
		for(int i = 2;i<=n;i+=2)arr[i] = p--;
	}
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
//d = 5
//5 10 4 9 3 8 2 7 1 6
//d = 5
// 5 11 4 10 3 9 2 8 1 7 6
//11 5 10 4 9 3 8 2 7 1 6
