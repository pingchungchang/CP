#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<m;i++){
		string tmp = arr[0];
		for(char j = 'a';j<='z';j++){
			tmp[i] = j;
			bool flag = true;
			for(int k = 0;k<n;k++){
				int d = 0;
				for(int l = 0;l<m;l++){
					if(arr[k][l] != tmp[l])d++;
				}
				if(d>1)flag = false;
			}
			if(flag){
				cout<<tmp<<'\n';
				return;
			}
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
