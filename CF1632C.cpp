#include <bits/stdc++.h>
using namespace std;

int a,b;
int ans;
void solve(){
	cin>>a>>b;;
	ans = INT_MAX;
	for(int i = 0;i<=b;i++){
		if((i|b) == b){
			ans = min(ans,abs(a-i)+1);
		}
	}
	ans = min(ans,b-a);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i  =0;i<t;i++)solve();
}
