#include <bits/stdc++.h>
using namespace std;

const int mxn = 404;
string arr[mxn];
int n,m,ans;

int calc(int r){
	int udp[m+1][2] = {},ddp[m+1][2] = {};
	for(int i = 1;i<=m;i++){
		int c = 0;
		for(int j = r-1;j>=0&&arr[j][i] != '#';j--){
			if(arr[j][i] == 'm')c++;
			if(c>1)break;
			if(!c)udp[i][0] = max(udp[i][0],r-j);
			else udp[i][1] = max(udp[i][1],r-j);
		}
		c = 0;
		for(int j = r+1;j<=n&&arr[j][i] != '#';j++){
			if(arr[j][i] == 'm')c++;
			if(c>1)break;
			if(!c)ddp[i][0] = max(ddp[i][0],j-r);
			else ddp[i][1] = max(ddp[i][1],j-r);
		}
		udp[i][1] = max(udp[i][1],udp[i][0]);
		ddp[i][1] = max(ddp[i][1],ddp[i][0]);
	}
	int re = 0;
	for(int i = 1;i<=m;i++){
		int c = 0;
		for(int j = i;j<=m;j++){
			if(arr[r][j] == '#')break;
			if(arr[r][j] == 'm')c++;
			if(c>1)break;
			if(j-i<=1)continue;
			if(c == 0){
				if(udp[i][1]&&ddp[i][0]&&ddp[j][0]&&udp[j][0])
					re = max(re,min(udp[i][1],udp[j][0])*2+min(ddp[i][0],ddp[j][0])*2+(j-i+1));
				if(udp[i][0]&&ddp[i][1]&&ddp[j][0]&&udp[j][0])
					re = max(re,min(udp[i][0],udp[j][0])*2+min(ddp[i][1],ddp[j][0])*2+(j-i+1));
				if(udp[i][0]&&ddp[i][0]&&ddp[j][1]&&udp[j][0])
					re = max(re,2*min(udp[i][0],udp[j][0])+2*min(ddp[i][0],ddp[j][1])+(j-i+1));
				if(udp[i][0]&&ddp[i][0]&&ddp[j][0]&&udp[j][1])
					re = max(re,2*min(udp[i][0],udp[j][1])+2*min(ddp[i][0],ddp[j][0])+(j-i+1));
			}
			else{
				if(udp[i][0]&&ddp[i][0]&&ddp[j][0]&&udp[j][0])
					re = max(re,2*min(udp[i][0],udp[j][0])+2*min(ddp[i][0],ddp[j][0])+(j-i+1));
			}
		}
	}
	/*
	cout<<r<<":"<<re<<endl;
	for(int i = 1;i<=m;i++)cout<<udp[i][0]<<' ';cout<<endl;
	for(int i = 1;i<=m;i++)cout<<udp[i][1]<<' ';cout<<endl;
	for(int i = 1;i<=m;i++)cout<<ddp[i][0]<<' ';cout<<endl;
	for(int i = 1;i<=m;i++)cout<<ddp[i][1]<<' ';cout<<endl;

   */
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	arr[0] = string(m+2,'#');
	arr[n+1] = arr[0];
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i] = "#"+arr[i]+"#";
	/*
	for(int i = 0;i<=n+1;i++)cout<<arr[i]<<endl;
	cout<<":"<<endl;

   */
	for(int i = 1;i<=n;i++){
		ans = max(ans,calc(i));
	}
	cout<<ans;
}
