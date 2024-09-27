#include <bits/stdc++.h>
//#include <climits>
//#include <curses.h>



#include <stdio.h>
using namespace std;
void beep() {
  cout << "\a" << flush;
}

const int maxn = 100 + 10; int A[maxn];
int main() {
    int a = INT_MAX;
    long long b = LONG_MIN;
    beep();

    char d=(char)(7);
    printf("%c\n",d);

    cout<<32e-3+400<<endl;
    cout<<sizeof(float)*8<<" "<<sizeof(double)*8<<" "<<sizeof(long double)*8<<endl; //in bits


    cout<<1492L<<endl; //tells the program to save as long
    char alarm = '\007';
    cout << alarm << "Don't do that again! \a\n";
    cout << "Ben \"Buggsiel\" Hacker\nwas here!\n";

    cout << "\aOperation \"HyperHype)\" is now activated! \n"; 
    cout << "Enter your agent code: _____\b\b\b\b\b\b";  //go back
    long code;
    cin >>code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z\u00E23!\n"; 
    
    return 0;
}

