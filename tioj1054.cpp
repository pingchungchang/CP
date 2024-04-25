#include <iostream>
#include<string>
using namespace std;


int main(){
    string s;
    int N;
    int k=7;
    cin >> s>>N;
    if(s=="Monday"){
        k = 1;
    }
    else if(s=="Tuesday"){
        k = 2;
    }
    else if(s=="Wednesday"){
        k = 3;
    }
    else if(s=="Thursday"){
        k = 4;
    }
    else if(s=="Friday"){
        k = 5;
    }
    else if(s=="Saturday"){
        k = 6;
    }
    k += N % 7;
    k = k % 7;
    if(k==1){
        cout << "Monday" << endl;
    }
    else if(k==2){
        cout << "Tuesday" << endl;
    }
    else if(k==3){
        cout << "Wednesday" << endl;
    }
    else if(k==4){
        cout << "Thursday" << endl;
    }
    else if(k==5){
        cout << "Friday" << endl;
    }
    else if(k==6){
        cout << "Saturday" << endl;
    }
    else{
            cout << "Sunday" << endl;
    }
}