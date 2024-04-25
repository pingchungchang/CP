#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string arr[n];
	bool flag[n] = {};
	int ans = 0;
	for(int i  = 0;i<n;i++){
		cin>>arr[i];
		for(int j = 0;j<i;j++){
			if(arr[i] == arr[j])flag[i] = true;
		}
	}
	for(int i = 0;i<n;i++){
		if(flag[i]){
			ans++;
			flag[i] = false;
			for(int j = 0;j<arr[i].size();j++){
				char p = arr[i][j];
				for(char c = '0';c<='9';c++){
					arr[i][j] = c;
					bool f = true;
					for(int l = 0;l<n;l++){
						if(l == i)continue;
						if(arr[i] == arr[l])f = false;
					}
					if(f){
						flag[i] = true;
						break;
					}
				}
				if(!flag[i])arr[i][j] = p;
				else break;
			}
		}
	}
	cout<<ans<<'\n';
	for(auto &i:arr)cout<<i<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
