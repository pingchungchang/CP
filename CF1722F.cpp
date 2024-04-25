#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> v(n+2,vector<char>(m+2,'.'));
	for(int i = 1;i<=n;i++)for(int j= 1;j<=m;j++)cin>>v[i][j];
	for(int i = 1;i<=n-1;i++){
		for(int j = 1;j<=m-1;j++){
			int cnt = 0;
			for(int asd = 0;asd<=1;asd++){
				for(int asdd = 0;asdd<=1;asdd++){
					if(v[i+asd][j+asdd] == '*')cnt++;
				}
			}
			if(cnt>3){
				cout<<"NO\n";
				return;
			}
			if(cnt == 3){
				for(int k = i;k<=i+1;k++){
					for(int l = j;l<=j+1;l++){
						if(v[k][l] == '*'){
							for(int d = -1;d<=1;d++){
								for(int dd = -1;dd<=1;dd++){
									if(k+d<=i+1&&k+d>=i&&l+dd<=j+1&&l+dd>=j)continue;
									if(v[k+d][l+dd] == '*'){
										cout<<"NO\n";
										return;
									}
								}
							}
						}
					}
				}
				v[i][j] = v[i+1][j] = v[i][j+1] = v[i+1][j+1] = '.';
			}
		}
	}
	for(auto &i:v)for(auto &j:i){
		if(j == '*'){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

