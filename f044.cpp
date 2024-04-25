#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	b/=a;
	b++;
	int ans =0;
	int i =1;
	while((i&b) == 0){
		i<<=1;
		ans++;
	}
	cout<<ans;
}
