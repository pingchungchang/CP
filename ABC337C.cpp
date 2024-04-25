#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
int nxt[mxn];
int N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	int h;
	for(int i = 1;i<=N;i++){
		int k;
		cin>>k;
		if(k == -1)h = i;
		else nxt[k] = i;
	}
	while(h){
		cout<<h<<' ';
		h = nxt[h];
	}
	return 0;
}
