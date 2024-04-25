#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a;
	cin>>n>>m>>a;
	int x = (n/a);
	if(x*a<n)x++;
	int y = (m/a);
	if(y*a<m)y++;
	cout<<1LL*x*y;
}
