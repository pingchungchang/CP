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
int main(){
	io
	int m,n;
	cin>>m>>n;
	string arr[m][n];
	for(int i = 0;i<m;i++){
		for(int j =0 ;j<n;j++)cin>>arr[i][j];
	}
	int row[m],col[n];
	for(int i = 0;i<m;i++)row[i] = i;
	for(int i = 0;i<n;i++)col[i] = i;
	int p;
	cin>>p;
	while(p--){
		char t;
		cin>>t;
		if(t == 'R'){
			int a,b;
			cin>>a>>b;
			a--,b--;
			swap(row[a],row[b]);
		}
		else if(t == 'C'){
			int a,b;
			cin>>a>>b;
			a--,b--;
			swap(col[a],col[b]);
		}
		else{
			int sx,sy,ex,ey;
			cin>>sx>>sy>>ex>>ey;
			sx--,sy--,ex--,ey--;
			swap(arr[row[sx]][col[sy]],arr[row[ex]][col[ey]]);
		}
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++)cout<<arr[row[i]][col[j]]<<' ';cout<<'\n';
	}
	return 0;
}

