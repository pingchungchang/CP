#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 505;
int n;
pii dir[] = {{1,0},{0,1},{1,1},{1,-1}};
string arr[mxn];
bool flag = false;

void solve(){
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = "."+arr[i]+".";
	}
	arr[0] = arr[n+1] = string(n+2,'.');
	int ans[3] = {};
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			int flag = 0;
			for(char tar = 'A';tar<='C';tar++){
				for(auto &d:dir){
					if(arr[i-d.fs][j-d.sc] == tar)continue;
					pii now = {i,j};
					int C = 0;
					while(arr[now.fs][now.sc] == tar){
						now.fs += d.fs;
						now.sc += d.sc;
						C++;
						if(C>5)break;
					}
					if(C == 5)ans[tar-'A']++,flag |= (1<<(tar-'A'));
				}
			}
		}
	}
	cout<<"A "<<ans[0]<<'\n'<<"B "<<ans[1]<<"\nC "<<ans[2]<<"\n\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n){
		if(!n)return 0;
		solve();
		for(int i = 0;i<=n+2;i++)arr[i].clear();
	}
}
