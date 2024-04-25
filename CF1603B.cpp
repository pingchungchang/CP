#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x,y;
	cin>>x>>y;
	if(x == y)cout<<x<<'\n';
	else if(x<y)cout<<y-x<<'\n';
	else cout<<y+x<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
