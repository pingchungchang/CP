#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string arr[101];
pii dir[] = {{1,0},{0,1},{1,1}};

void flip(int a,int b){
	arr[a][b] = (arr[a][b] == '1'?'0':'1');
	return;
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	vector<tuple<int,int,int,int,int,int>> ans;
	for(int i = 0;i<n-2;i++){
		for(int j = 0;j<m-2;j++){
			if(arr[i][j] == '1'){
				ans.push_back(make_tuple(i+1,j+1,i+2,j+1,i+1,j+2));
				flip(i,j);flip(i+1,j);flip(i,j+1);
			}
		}
	}
	for(int i = 0;i<n-2;i++){
		if(arr[i][m-2] == '1'&&arr[i][m-1] == '1'){
			ans.push_back(make_tuple(i+1,m-1,i+1,m,i+2,m-1));
			flip(i,m-2);flip(i,m-1);flip(i+1,m-2);
		}
		else if(arr[i][m-2] == '1'){
			ans.push_back(make_tuple(i+1,m-1,i+2,m-1,i+2,m));
			flip(i,m-2);flip(i+1,m-1);flip(i+1,m-2);
		}
		else if(arr[i][m-1] == '1'){
			ans.push_back(make_tuple(i+1,m,i+2,m-1,i+2,m));
			flip(i,m-1);flip(i+1,m-1);flip(i+1,m-2);
		}
	}
	for(int i = 0;i<m-2;i++){
		if(arr[n-1][i] == '1'&&arr[n-2][i] == '1'){
			ans.push_back(make_tuple(n-1,i+1,n,i+1,n-1,i+2));
			flip(n-1,i);flip(n-2,i);flip(n-2,i+1);
		}
		else if(arr[n-1][i] == '1'){
			ans.push_back(make_tuple(n,i+1,n,i+2,n-1,i+2));
			flip(n-1,i);flip(n-1,i+1);flip(n-2,i+1);
		}
		else if(arr[n-2][i] == '1'){
			ans.push_back(make_tuple(n-1,i+1,n,i+2,n-1,i+2));
			flip(n-2,i);flip(n-1,i+1);flip(n-2,i+1);
		}
	}
	vector<pii> v1,v2;
	for(int i = n-2;i<n;i++){
		for(int j = m-2;j<m;j++)if(arr[i][j] == '1')v1.push_back({i,j});else v2.push_back({i,j});
	}

	if(v1.size() == 3||v1.size() == 4){
		ans.push_back(make_tuple(v1[0].fs+1,v1[0].sc+1,v1[1].fs+1,v1[1].sc+1,v1[2].fs+1,v1[2].sc+1));
		for(int i = 0;i<3;i++)flip(v1[i].fs,v1[i].sc);
	}

	v1.clear();v2.clear();
	for(int i = n-2;i<n;i++){
		for(int j = m-2;j<m;j++)if(arr[i][j] == '1')v1.push_back({i,j});else v2.push_back({i,j});
	}

	if(v1.size() == 1){
		ans.push_back(make_tuple(v1[0].fs+1,v1[0].sc+1,v2[0].fs+1,v2[0].sc+1,v2[1].fs+1,v2[1].sc+1));
		flip(v1[0].fs,v1[0].sc);flip(v2[0].fs,v2[0].sc);flip(v2[1].fs,v2[1].sc);
	}

	v1.clear();v2.clear();
	for(int i = n-2;i<n;i++){
		for(int j = m-2;j<m;j++)if(arr[i][j] == '1')v1.push_back({i,j});else v2.push_back({i,j});
	}

	if(v1.size() == 2){
		ans.push_back(make_tuple(v1[0].fs+1,1+v1[0].sc,v2[0].fs+1,v2[0].sc+1,v2[1].fs+1,v2[1].sc+1));
		flip(v1[0].fs,v1[0].sc);flip(v2[0].fs,v2[0].sc);flip(v2[1].fs,v2[1].sc);
	}
	v1.clear();v2.clear();
	for(int i = n-2;i<n;i++){
		for(int j = m-2;j<m;j++)if(arr[i][j] == '1')v1.push_back({i,j});else v2.push_back({i,j});
	}
	if(v1.size() == 3){
		ans.push_back(make_tuple(v1[0].fs+1,v1[0].sc+1,v1[1].fs+1,v1[1].sc+1,v1[2].fs+1,v1[2].sc+1));
		for(auto &i:v1)flip(i.fs,i.sc);
	}
	/*
	for(int i = 0;i<n;i++){
		for(int j =0 ;j<m;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
   */
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<' '<<get<3>(i)<<' '<<get<4>(i)<<' '<<get<5>(i)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
