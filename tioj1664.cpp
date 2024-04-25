#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v = {"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
void solve(){
	cout<<v[n%7]<<'\n';
}
int main(){
	while(cin>>n)solve();
}
