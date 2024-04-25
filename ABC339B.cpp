#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 110;
pii dir[] = {{-1,0},{0,1},{1,0},{0,-1}};
int pt = 0;
int arr[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int h,w,n;
	cin>>h>>w>>n;
	pii now = make_pair(1,1);
	for(int i = 0;i<n;i++){
		if(arr[now.fs][now.sc])pt+=3;
		else pt ++;
		pt %= 4;
		arr[now.fs][now.sc]^=1;
		now.fs += dir[pt].fs;
		now.sc += dir[pt].sc;
		if(now.fs<=0)now.fs += h;
		if(now.sc<=0)now.sc += w;
		if(now.fs>h)now.fs -= h;
		if(now.sc>w)now.sc -= w;
	}
	for(int i = 1;i<=h;i++){
		for(int j = 1;j<=w;j++){
			cout<<(arr[i][j]?"#":".");
		}
		cout<<'\n';
	}
}
