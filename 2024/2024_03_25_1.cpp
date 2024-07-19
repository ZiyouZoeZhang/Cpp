/*#include <iostream>
using namespace std;

int main(){
    string a;
    cout<<"input"<<endl;
    cin>>a;
    cout<<a<<"ceyuicgeygyger"<<endl;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}