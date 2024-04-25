#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int f(int now){
	int tmp = 0;
	int biggest =-1;
	for(int i = 0;i<n;i++){
		if(i == now)continue;
		if(v[i]>biggest){
			tmp++;
		}
		biggest = max(biggest,v[i]);
	}
	return tmp;
}
void solve(){
	cin>>n;
	v = vector<int>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	
	int ans = 0;
	for(int i = -1;i<n;i++){
		ans = max(ans,f(i));
	}
	
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
