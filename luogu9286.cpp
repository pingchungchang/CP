#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
vector<vector<int>> arr;
int N,M,Q;
int row[mxn],col[mxn],cnt;
int rans[mxn],cans[mxn];

void del(int r,int c){
	assert(rans[r]&&cans[c]&&rans[r] == c&&cans[c] == r);
	rans[r] = cans[c] = 0;
	cnt--;
	return;
}
void add(int r,int c){
	if(rans[r]&&cans[c])return;
	assert(!rans[r]&&!cans[c]);
	rans[r] = c,cans[c] = r;
	cnt++;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>Q;
	arr = vector<vector<int>>(N+1,vector<int>(M+1,0));
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			cin>>arr[i][j];
			row[i] = max(row[i],arr[i][j]);
			col[j] = max(col[j],arr[i][j]);
		}
	}
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			if(arr[i][j]>=max(row[i],col[j]))cnt++,rans[i] = j,cans[j] = i;
		}
	}
	while(Q--){
		/*
		for(int i = 1;i<=N;i++)cout<<rans[i]<<',';cout<<endl;
		for(int i = 1;i<=M;i++)cout<<cans[i]<<',';cout<<endl;cout<<endl;

	   */
		int r,c,v;
		cin>>r>>c>>v;
		arr[r][c] = v;
		row[r] = max(row[r],v);
		col[c] = max(col[c],v);
		if(rans[r]&&arr[r][rans[r]]<row[r])del(r,rans[r]);
		if(cans[c]&&arr[cans[c]][c]<col[c])del(cans[c],c);
		if(arr[r][c] == max(row[r],col[c]))add(r,c);
		cout<<cnt<<'\n';
	}
}
