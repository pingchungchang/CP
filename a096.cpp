#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	stringstream ss;
	getline(cin,s);
	for(int i = 0;i<s.size();i++){
		if(s[i] == ':')s[i] = ' ';
	}
	ss<<s;
	int a[3] = {};
	ss>>a[0]>>a[1]>>a[2];
	getline(cin,s);
	for(int i = 0;i<s.size();i++){
		if(s[i] == ':')s[i] = ' ';
	}
	ss.clear();
	ss<<s;
	int j;
	int b[3] = {};
	ss>>b[0]>>b[1]>>b[2];
	if(b[2]<a[2]){
		b[1]--;
		b[2]+= 60;
	}
	if(b[1]<a[1]){
		b[0]--;
		b[1]+=60;
	}
	if(b[0]<a[0])b[0]+= 24;
	if(b[0]-a[0]<10){
		cout<<0;
	}
	cout<<b[0]-a[0]<<':';
	if(b[1]-a[1]<10){
		cout<<0;
	}
	cout<<b[1]-a[1]<<':';
	if(b[2]-a[2]<10)cout<<0;
	cout<<b[2]-a[2];
	
}

/*

#include <iostream>
using namespace std;

void discount(  double& p1,double& p2  ){
     if(p1 != p2)return;
     p2/=2.0;
}
int main(){
    double p1, p2;
    cout << "Original price:" << endl;
    cin >> p1 >> p2;
    discount(p1,p2 );
    cout << "Price after discount:" << endl;
    cout << p1 << " " << p2 << endl;
    return 0;
}
 

*/
