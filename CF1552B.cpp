#include <bits/stdc++.h>
using namespace std;


int arr[50005][5] = {};
bool bigger(int a,int b){
	int wins = 0;
	for(int i = 0;i<5;i++){
		if(arr[a][i]<arr[b][i])wins++;
	}
	if(wins>=3)return true;
	else return false;
}
void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)for(int j = 0;j<5;j++)cin>>arr[i][j];
	int now = 0;
	for(int i = 0;i<n;i++){
		if(bigger(now,i) == false){
			now = i;
		}
//		cout<<i<<' '<<now<<endl;
	}
	bool real = true;
	for(int i = 0;i<now;i++){
		if(bigger(now,i) == false){
			real = false;
		}
	}
	if(real)cout<<now+1<<'\n';
	else cout<<-1<<'\n';
}
int main(){
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
