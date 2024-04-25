#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int n,m;
bool F = 0;

void solve(){
	//cout<<m<<' '<<n<<endl;
	vector<int> to[m];
	for(auto &i:to)i = vector<int>(n);
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			string s;
			cin>>s;
			//cout<<s[0]<<endl;
			if(s[0] == '|'){
				to[i][j] = j;
			}
			else{
				to[i][j] = j+1;
				to[i][j+1] = j;
				j++;
			}
		}
	}
	int ans[n] = {};
	for(int i = 0;i<n;i++){
		int now = i;
		for(int j = 0;j<m;j++){
			now = to[j][now];
		}
		ans[now] = i;
	}
	for(int i = 0;i<n;i++){
		cout<<(i?" ":"")<<ans[i]+1;
	}
	return;
}

int main(){
	while(cin>>n>>m){
		if(!n&&!m)return 0;
		if(F)cout<<'\n';
		solve();
		F = true;
	}
}
