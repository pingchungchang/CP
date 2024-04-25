#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<vector<int>> arr(5,vector<int>(n,0));
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		int ss = s.size();
		for(int j = 0;j<ss;j++){
			arr[s[j]-'a'][i]++;
		}
		for(int j = 0;j<5;j++){
			arr[j][i] = arr[j][i]*2-ss;
		}
	}
//	for(int i = 0;i<5;i++){
//		for(int j = 0;j<n;j++)cout<<arr[i][j]<<' ';
//		cout<<endl;
//	}
//	cout<<endl;
//	return;
	for(int i = 0;i<5;i++)sort(arr[i].begin(),arr[i].end());
	int ans = 0;
	for(int i = 0;i<5;i++){
		int p = n-1;
		int k = arr[i][n-1];
		while(k>0&&p>=0){
			p--;
			k += arr[i][p];
		}
		p++;
		ans = max(ans,n-p);
	}
	cout<<ans<<'\n';
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
	return 0;
}
