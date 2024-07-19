/*
ID: zz415821
TASK: palsquare
LANG: C++  
#include <cmath>               
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

bool checkPalindrome(string s){
    for (int i=0; i<s.size()/2; i++){
        if (s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}

string toBaseB(int n, int B) { 
    string result = ""; 
    while (n > 0) { 
        int remainder = n % B; 
        if (remainder >= 10) { 
            result += 'A' + (remainder - 10); // 对于大于10的基数 
        } else { 
            result += '0' + remainder; 
        } n /= B; 
    } 
    reverse(result.begin(), result.end()); 
    return result; 
}

int main(){
    int B;
    fin>>B;
    for (int i=1; i<300; i++){
        string qs=toBaseB(i*i, B);
        if (checkPalindrome(qs)){
            fout<<toBaseB(i, B)<<" "<<qs<<endl;
        }
    }
    //cout<<checkPalindrome(to_string(N))<<endl;
    return 0;
}
