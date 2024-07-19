/*
ID: zz415821
TASK: dualpal
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main (){

    std::ofstream fout ("dualpal.out");
    std::ifstream fin ("dualpal.in");

    int N, S;
    fin>>N>>S;
    while (N>0){
        S++;
        int c=0;
        for (int b=2; b<11; b++){
            if (checkPalindrome(toBaseB(S, b))) {
                c++;
                if (c>1){
                    fout<<S<<endl;
                    N--;
                    break;
                }
            }
        }
        
    }
    return 0;
}