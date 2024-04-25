#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	if(n&1){
		cout<<"1 2 3 ";
		for(int i = 5;i<=n-2;i+=2)cout<<i<<' '<<i-1<<' ';cout<<n-1<<' '<<n<<'\n';return;
	}
	else{
		for(int i = 2;i<=n-2;i+=2)cout<<i<<' '<<i-1<<' ';cout<<n-1<<' '<<n<<'\n';return;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}