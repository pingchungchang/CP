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
	int row[n] = {},col[m] = {};
	int cnt = 0;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		m = arr[i].size();
		for(int j = 0;j<m;j++){
			if(arr[i][j] == 'A'){
				row[i]++,col[j]++;
				cnt++;
			}
		}
	}

	bool two = false;
	pii p = {m-1,0};
	for(int i = 0;i<m;i++)if(arr[0][i] == 'P')p.fs = min(p.fs,i),p.sc = max(p.sc,i);
	for(int i = 0;i<n;i++){
		bool flag = true;
		for(int j = p.fs;j<=p.sc;j++){
			if(arr[i][j] == 'P')flag = false;
		}
		if(flag)two = true;
	}
	p = {m-1,0};
	for(int i = 0;i<m;i++)if(arr[n-1][i] == 'P')p.fs = min(p.fs,i),p.sc = max(p.sc,i);
	for(int i = 0;i<n;i++){
		bool flag = true;
		for(int j = p.fs;j<=p.sc;j++){
			if(arr[i][j] == 'P')flag = false;
		}
		if(flag)two = true;
	}
	p = {n-1,0};
	for(int i = 0;i<n;i++)if(arr[i][0] == 'P')p.fs = min(p.fs,i),p.sc = max(p.sc,i);
	for(int i = 0;i<m;i++){
		bool flag = true;
		for(int j = p.fs;j<=p.sc;j++){
			if(arr[j][i] == 'P')flag = false;
		}
		if(flag)two = true;
	}
	p = {n-1,0};
	for(int i = 0;i<n;i++)if(arr[i][m-1] == 'P')p.fs = min(p.fs,i),p.sc = max(p.sc,i);
	for(int i = 0;i<m;i++){
		bool flag = true;
		for(int j = p.fs;j<=p.sc;j++){
			if(arr[j][i] == 'P')flag = false;
		}
		if(flag)two = true;
	}

	if(cnt == 0){
		cout<<"MORTAL\n";
		return;
	}
	else if(cnt == n*m){
		cout<<"0\n";
		return;
	}
	if(row[0] == m||row[n-1] == m||col[0] == n||col[m-1] == n)cout<<"1\n";
	else if(two||arr[0][0] == 'A'||arr[0][m-1] == 'A'||arr[n-1][0] == 'A'||arr[n-1][m-1] == 'A')cout<<"2\n";
	else if(row[0]||row[n-1]||col[0]||col[m-1])cout<<"3\n";
	else cout<<"4\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		solve();
	}
}
