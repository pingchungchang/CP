#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans = 0;
	int pre = -k*3;
	for(int i = 0;i<n;i++){
		if(s[i] == '1'){
			pre = i;
			continue;
		}
		else{
			if(i-pre-1<k)continue;
			int pt = i;
			bool flag = false;
			for(;pt<n&&s[pt] == '0';pt++){
				if(pt == i+k||pt == n-1){
					ans++;
					pre = i;
					flag = true;
					break;
				}
			}
			if(!flag)pre = pt;
			i = pt;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
