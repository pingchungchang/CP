#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 3e6+10;
int pos[mxn],arr[mxn];
bitset<mxn> vis;


int main(){

	int c = 0;
	{
		int k = 0;
		char in;
		while((in = getchar()) != '\n'){
			if(in==' '){
				if(k)pos[k] = ++c;
				k = 0;
			}
			else if(in>='0'&&in<='9')k = k*10+(in-'0');
			else assert(false);
		}
		if(k)pos[k] = ++c;
	}

	int cc = 0;
	{
		int k = 0;
		char in;
		while((in = getchar()) != EOF&&in != '\n'){
			if(in == ' '){
				if(k)arr[++cc] = k;
				k = 0;
			}
			else if(in>='0'&&in<='9')k = k*10+(in-'0');
			else assert(false);
		}
		if(k)arr[++cc] = k;
	}

	if(c != cc){
		cout<<-1;
		return 0;
	}
	int n = c;
	int ans = 0;
	/*
	for(int i  = 1;i<=n;i++)cout<<pos[i]<<' ';cout<<endl;
	for(int i  = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<endl;
   */
	for(int i = 1;i<=n;i++)arr[i] = pos[arr[i]];
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		int now = i;
		c = 0;
		do{
			c++;
			vis[now] = true;
			now = arr[now];
		}while(!vis[now]);
		ans += c-1;
	}
	cout<<ans;
}
