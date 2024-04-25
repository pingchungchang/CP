#include <bits/stdc++.h>
using namespace std;

int arr[5][5];
void used(int k){
	for(int i = 0;i<5;i++)for(int j = 0;j<5;j++)if(arr[i][j] == k)arr[i][j] = -1;
}
int cnt(int r,int c){
	int returns = 0;
	if(arr[r][0]+arr[r][1]+arr[r][2]+arr[r][3]+arr[r][4]-arr[r][c] == -4)returns++;
	if(arr[0][c]+arr[1][c]+arr[2][c]+arr[3][c]+arr[4][c]-arr[r][c] == -4)returns++;
	if(r == c){
		int sum = 0;
		for(int i = 0;i<5;i++)sum += arr[i][i];
		sum -= arr[r][c];
		if(sum == -4)returns++;
	}
	if(r+c == 4){
		int sum = 0;
		for(int i = 0;i<5;i++)sum += arr[i][4-i];
		sum -= arr[r][c];
		if(sum == -4)returns++;
	}
	return returns;
}
int main(){
	for(int i = 0;i<5;i++)for(int j = 0;j<5;j++)cin>>arr[i][j];
	int n;
	while(cin>>n){
		if(n == -1)break;
		used(n);
	}
	int pts[5][5] = {};
	for(int i = 0;i<5;i++)for(int j = 0;j<5;j++){
		if(arr[i][j] != -1)pts[i][j] = cnt(i,j);
		else pts[i][j] = -1;
	}
	pair<int,int> ans = make_pair(pts[0][0],arr[0][0]);
	for(int i = 0;i<5;i++)for(int j = 0;j<5;j++){
		if(pts[i][j] == ans.first){
			ans.second = min(ans.second,arr[i][j]);
		}
		else ans = max(ans,make_pair(pts[i][j],arr[i][j]));
	}
	cout<<ans.second;
}
