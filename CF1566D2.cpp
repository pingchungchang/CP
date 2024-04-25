#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> arr(n,vector<pair<int,int>>(m));
	vector<pair<int,int>> v(n*m);
	for(int i = 0;i<n*m;i++){
		cin>>v[i].first;
		v[i].second = i;
	}
	sort(v.begin(),v.end());
	int now =0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			arr[i][j] = v[now];
			now++;
		}
		int r = m-1;
		int l = m-1;
		while(l >= 0){
			arr[i][l].second = -arr[i][l].second;
			l--;
			if(arr[i][l].first != arr[i][r].first){
				sort(arr[i].begin()+l+1,arr[i].begin()+r+1);
				r = l;
			}
		}
		sort(arr[i].begin()+l+1,arr[i].begin()+r+1);
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			arr[i][j].second = -arr[i][j].second;
//			cout<<arr[i][j].second<<' ';
		}
//		cout<<endl;
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			for(int k = j-1;k>=0;k--){
				if(arr[i][j].second>arr[i][k].second)ans++;
			}
		}
	}
	cout<<ans<<'\n';
	cout<<endl;
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();

}
