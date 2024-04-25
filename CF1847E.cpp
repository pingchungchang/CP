#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int calc(int a,int b,int c){
	if(a+b<=c)return -1;
	int s = a+b+c;
	return s*(s-a*2)*(s-b*2)*(s-c*2);
}

int main(){
	for(int i = 1;i<=4;i++)for(int j = i;j<=4;j++)for(int k = j;k<=4;k++)cout<<i<<' '<<j<<' '<<k<<":"<<calc(i,j,k)<<'\n';
}
