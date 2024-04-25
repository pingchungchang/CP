#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main(){
	ll n,l,r;
	cin>>n>>l>>r;
	ll total = 0;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		k %= (l+r);
		total ^= k/l;
	}
	cout<<(total?"First":"Second");
	return 0;
}
/*
eg: l = 3,r = 5
0:0
1:0
2:0
3 1
4 1
5 1
6 2
7 2

8 0
9 0
10 0
11 1
eg: l = 3 r = 7
0 0
1 0
2 0
3 1
4 1
5 1
6 2
7 2
8 2
9 3

10 0

eg: l = 1,r = 2
0 0
1 1
2 2

3 0
4 1
5 2
2 0 0
eg: l = 1 r = 4
0 0
1 1
2 2
3 3
4 4

*/
