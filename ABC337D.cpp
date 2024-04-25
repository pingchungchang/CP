#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

vector<string> arr;
int H,W,K;
vector<vector<int>> row,col;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>H>>W>>K;
	arr = vector<string>(H+2);
	for(int i = 1;i<=H;i++){
		cin>>arr[i];
		arr[i] = "x"+arr[i]+"x";
	}
	arr[0] = arr[H+1] = string(W+2,'x');
	row = vector<vector<int>>(H+2,vector<int>(W+2,0));
	col = row;
	for(int i = 1;i<=H;i++){
		for(int j = 1;j<=W;j++){
			row[i][j] += row[i][j-1];
			if(arr[i][j] != 'o')row[i][j]++;
			col[i][j] += col[i-1][j];
			if(arr[i][j] != 'o')col[i][j]++;
		}
	}
	int ans = 1e9;
	for(int i = 1;i<=H;i++){
		int pt = 0;
		for(int j = 1;j+K-1<=W;j++){
			if(pt<j)pt = j;
			while(arr[i][pt] != 'x')pt++;
			if(pt-j+1<=K)continue;
			ans = min(ans,row[i][j+K-1]-row[i][j-1]);
		}
	}
	for(int i = 1;i<=W;i++){
		int pt = 0;
		for(int j = 1;j+K-1<=H;j++){
			if(pt<j)pt = j;
			while(arr[pt][i] != 'x')pt++;
			if(pt-j+1<=K)continue;
			ans = min(ans,col[j+K-1][i]-col[j-1][i]);
		}
	}
	cout<<(ans>K?-1:ans);
}
