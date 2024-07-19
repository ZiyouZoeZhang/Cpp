#include <iostream>
#include <vector>
#include <set>

using namespace std;
set <int> myList;
long long finalCost=10000000000;
int i_delete, i_insert, extras;
int cal_cost(int length);

int main()
{
    int m,n;
    cout<<"please enter: length of array, cost to delete, cost to insert: \n";
    cin>>m>>i_delete>>i_insert;
    for (int i=0; i<m; i++)
    {
        cin>>n;
        if (myList.find(n)!=myList.end()) extras+=i_delete;
        myList.insert(n);
    }

    if(myList.find(1)==myList.end())
    {
        myList.insert(1);
        extras+=i_insert;
    }

    for (set<int>::iterator  itr=myList.begin(); itr!=myList.end(); ++itr)
    {
        int this_cost=cal_cost(*itr);
        if(this_cost<finalCost) finalCost=this_cost;
    }
    
    finalCost+=extras;
    cout<<"final Cost: "<<finalCost<<endl;
    return 0;
}

int cal_cost(int length)
{
    int tempCost=0; 
    int index=1;
    for (set<int>::iterator  itr=myList.begin(); itr!=myList.end(); ++itr){
        if (*itr != length) index++;
        else break;
    }
    tempCost+=(length-index)*i_insert;
    tempCost+=(myList.size()-index)*i_delete;
    //tempCost+=((*--myList.end())-(length+(myList.size()-1)))*i_delete;
    //(8-6)*i_delete;
    /*
    int tempCost = 0;
    //cout<<length<<"target length"<<endl;
    for (int i=1; i<=(*--myList.end()); i++)
    {
        if(i<length && myList.find(i)==myList.end()) //当他需要被插入 = 小于target length && 没有already contained in set
        {
            tempCost+=i_insert;
            cout<<i<<" need to be inserted: "<<tempCost<<endl;
        } else if (i>length && myList.find(i)!=myList.end()) //当他需要被删除 = 大于target length && already contained in set
        {
            tempCost+=i_delete;
            cout<<i<<" need to be deleted"<<tempCost<<endl;
        }
    }
    cout<<"this cost: "<<tempCost<<endl;
    cout<<"**************************"<<endl;
    */
    return tempCost;
}