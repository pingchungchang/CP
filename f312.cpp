#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans =INT_MIN;
	int n;
	int a1,a2,b1,b2,c1,c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	cin>>n;
	for(int a = 0;a<=n;a++){
		int b = n-a;
		ans = max(ans,a1*a*a+b1*a+c1+a2*b*b+b2*b+c2);
	}
	cout<<ans;
}
