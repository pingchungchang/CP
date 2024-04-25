#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	vector<int> pref(n+1,0);
	for(int i = 1;i<=n;i++){
		cin>>pref[i];
		pref[i]+=pref[i-1];
	}
	int ans= 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			ans = max(ans,pref[n]-(pref[j]-pref[i-1])+(j-i+1)-(pref[j]-pref[i-1]));
		}
	}
	cout<<ans;
}

