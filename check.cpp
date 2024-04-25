#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

string s,ss;

int main(){
	ll c = 0;
	while(true){
		cout<<time(NULL)<<endl;
		system("test > input.txt");
		system("a < input.txt > output1.txt");
		system("brute < input.txt > output2.txt");
		ifstream fin("output1.txt");
		string in;
		while(getline(fin,in))s += in,s += '\n';
		fin = ifstream("output2.txt");
		while(getline(fin,in))ss += in,ss+='\n';
		if(s != ss){
			cout<<"ERROR:\n";
			fin = ifstream("input.txt");
			while(getline(fin,s))cout<<s<<endl;
			exit(0);
		}
		Sleep(1000);
	}
}
