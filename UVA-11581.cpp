#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int enc(vector<vector<int>> arr){
	int ans = 0;
	for(int i = 1;i<=3;i++){
		for(int j = 1;j<=3;j++){
			ans += arr[i][j]*(1<<(3*(i-1)+(j-1)));
		}
	}
	return ans;
}
void pv(vector<vector<int>> arr){
	for(int i = 0;i<5;i++){
		for(int j =0;j<5;j++)cout<<arr[i][j]<<' ';
		cout<<endl;
	}
}
void solve(){
	set<int> st;
	vector<vector<int>> arr(5,vector<int>(5,0));
	for(int i = 1;i<=3;i++)for(int j = 1;j<=3;j++){
		char c;
		cin>>c;
		arr[i][j] = c-'0';
	}
	int ans = 0;
	while(st.find(enc(arr)) == st.exnd()&&enc(arr) != 0){
		st.insert(enc(arr));	
		int arr2[5][5] = {};
		for(int i = 1;i<=3;i++){
			for(int j = 1;j<=3;j++){
				arr2[i][j] = (arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j-1])%2;
			}
		}
		for(int i = 1;i<=3;i++)for(int j = 1;j<=3;j++)arr[i][j] = arr2[i][j];
	}
	cout<<(int)st.size()-1<<'\n';
	return;

}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

