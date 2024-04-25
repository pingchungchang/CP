#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	vector<bool> v(n+2,false);
	for(ll i = 1;i<=n;i++){
		char c;
		cin>>c;
		v[i] = c-'0';
	}
	int ans = 0;
	v[n+1] = 0;
	int s = -1;
	for(int i = 1;i<=n+1;i++){
		if(v[i] == 0){
//			cout<<s<<' '<<i<<endl; 
			if(s == -1)continue;
			ans += (i-s+1)/2;
			s = -1;
		}
		else if(s == -1){
			s = i;
		}
	}
	cout<<ans;
}

