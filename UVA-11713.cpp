#include <bits/stdc++.h>
using namespace std;

int main(){
	set<char> vowels;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int chars[26] = {};
	chars[0] = 1;
	chars['e'-'a'] = 1;
	chars['i'-'a'] = 1;
	chars['o'-'a'] = 1;
	chars['u'-'a'] = 1;
	for(int asd=0;asd<n;asd++){
		string a,b;
		cin>>a>>b;
		bool done =true;
		if(a.size()!=b.size())done = false;
		else{
			for(int i =0;i<a.size();i++){
				if((chars[a[i]-'a']&chars[b[i]-'a']) != 1&&a[i]!=b[i]){
					done = false;
					break;
				}
			}
		}
		if(done)cout<<"Yes";
		else cout<<"No";
		if(asd!= n-1)cout<<'\n';
	}
}
