#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int l,n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>l>>n>>m;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		v[i]--;
	}
	vector<int> arr(n);
	for(int i = 0;i<n;i++)arr[i] = i;
	for(int i = 0;i<m;i++){
		vector<int> buf = arr;
		for(int j = 0;j<n;j++){
			arr[v[j]] = buf[j];
		}
	}
	for(int asd =0;asd<l;asd++){
		string s;
		cin>>s;
		while(s.size()<n)s +='#';
		string s2 = s;
		for(int i = 0;i<n;i++){
			s[i] = s2[arr[i]];
		}
		cout<<s<<'\n';
	}
	return 0;
}
