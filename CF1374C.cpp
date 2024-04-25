#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	for(int i = 0;i<=n/2;i++){
		int c = 0,sum = i;
		bool flag = true;
		for(int j = 0;j<n;j++){
			if(s[j] == '('){
				if(c<n/2-i)sum++;
				c++;
			}
			else sum--;
			if(sum<0){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<i<<'\n';
			return;
		}
	}
	assert(false);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
