#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int special=1,capital = 1,alphabet = 1,numbers = 1;
    string password;
    int k;
    cin >> k >> password;
    string sn = "!@#$%^&*()-+";
    string A = "ABCDEFGHIJKLMNOPQRUSTVWXYZ";
    string a = "abcdefghijklmnopqrstuvwxyz";
    string num = "01234567890";
    unordered_map<char, int> map;
    for (int i = 0; i < A.size();i++){
        map[A[i]] = 1;
    }
    for (int i = 0; i <a.size();i++){
        map[a[i]] = 2;
    }
    for (int i = 0; i < num.size();i++){
        map[num[i]] = 3;
    }
    for (int i = 0; i < sn.size();i++){
        map[sn[i]] = 4;
    }
    for (int i = 0;i<password.size();i++){
        if(map[password[i]]==1){
            capital = 0;
        }
        else if(map[password[i]]==2){
            alphabet = 0;
        }
        else if(map[password[i]]==3){
            numbers = 0;
        }
        else{
            special = 0;
        }

    }
    // cout << capital << alphabet << numbers << special;
    if(6>password.size()&&6-password.size()>special+capital+alphabet+numbers) cout << 6 - password.size();
    else cout << special + capital + alphabet + numbers;
}