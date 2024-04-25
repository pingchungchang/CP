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
	string a,b,c;
	int cnt = 0;
	cin>>a>>b>>c;
	for(int i = 0;i<n;i++){
		if(a[i] == c[i]||b[i] == c[i]){
			cnt++;
		}
	}
	cout<<(cnt == n?"NO\n":"YES\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
