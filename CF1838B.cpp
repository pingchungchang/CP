#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n+1],pos[n+1];
	int one,two,lst;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(arr[i] == 1)one = i;
		else if(arr[i] == 2)two = i;
		else if(arr[i] == n)lst = i;
	}
	if(one>=two)swap(one,two);
	if(lst>=two){
		cout<<two<<' '<<lst<<'\n';
	}
	else if(lst<=one)cout<<lst<<' '<<one<<'\n';
	else cout<<1<<' '<<1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
