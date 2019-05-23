#include <iostream>
using namespace std;

class hashTable{
public: int* Table;
        int max_size;

        hashTable(int max_)
        {
            max_size=max_;
            Table=new int[max_];
            for(int i=0;i<max_;i++)
            {
                Table[i]=-1;
            }
        }
        int hashFunction(int element)
        {
            return element%max_size;
        }
        int insert_hashing(int element)
        {
            int index=hashFunction(element);
            Table[index]=element;
        }

};

int main()
{
    int n;
    cin>>n;
    int x;
    hashTable h(10);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        h.insert_hashing(x);
    }
    for(int i=0;i<h.max_size;i++)
    {
        if(h.Table[i]==-1) continue;

        cout<<h.Table[i]<<" has hashing index "<<i<<endl;
    }
    return 0;
}
