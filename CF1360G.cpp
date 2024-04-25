#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int arr[55][55];

int pref(int r,int c){
	int re = 0;
	for(int i = 0;i<=r;i++)re += arr[i][c];
	return re;
}

bool check(int n,int m,int a,int b){
	for(int i = 0;i<n;i++){
		int s =0;
		for(int j = 0;j<m;j++){
			s += arr[i][j];
		}
		if(s != a)return false;
	}
	for(int i = 0;i<m;i++){
		int s = 0;
		for(int j = 0;j<n;j++)s += arr[j][i];
		if(s != b)return false;
	}
	return true;
}

void solve(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	memset(arr,0,sizeof(arr));
	bool flag = false;
	for(int i = 0;i<n;i++){
		if(flag)break;
		for(int j = 0;j<m;j++){
			if(flag)break;
			if(!arr[i][j]){
				pii now = {i,j};
				do{
					arr[now.fs][now.sc] = 1;
					now.fs++;now.sc++;
					if(now.fs>=n)now.fs -= n;
					if(now.sc>=m)now.sc -= m;
				}while(arr[now.fs][now.sc] != 1);
			}
			if(check(n,m,a,b))flag = true;
		}
	}
	if(flag){
		cout<<"YES\n";
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++)cout<<arr[i][j];cout<<'\n';
		}
		return;
	}
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
