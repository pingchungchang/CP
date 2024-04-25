#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	cout<<((n&INT_MIN)>>31)+((!((n&INT_MIN)>>31))&&n);
}
