#include <iostream>
#include<list>
using namespace std;

class hashTable{
public: list<int>* Table;
        int max_size;


        hashTable(int max_)
        {
            max_size=max_;
            Table=new list<int>[max_];
        }
        int hashFunction(int element)
        {
            return element%max_size;
        }
        void insert(int element)
        {
            int index=hashFunction(element);
            Table[index].push_back(element);
        }
        bool delete_hash(int element)
        {
            int index=hashFunction(element);//find the bucket in which the element should be found;
            for(list<int>::iterator it=Table[index].begin();it!=Table[index].end();it++)
            {
                int element_required=*it;
                if(element_required==element)
                {
                    Table[index].erase(it);
                    return 1;
                }
            }
            return 0;
        }
        void print()
        {
            for(int i=0;i<max_size;i++)
            {
                for(list<int>::iterator it=Table[i].begin();it!=Table[i].end();it++)
                {
                    cout<<*it<<" has hashing index "<<i<<endl;
                }
                cout<<"================================"<<endl;
            }
        }


};

int main()
{
    hashTable h(10);
    int n,x;
    cout<<"Enter number of elements you want to insert to hashTable followed by numbers"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        h.insert(x);
    }
    cout<<"HashTable content"<<endl;
    h.print();
    cout<<"Enter number of elements you want to delete from hashTable followed by numbers"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
       if(h.delete_hash(x))cout<<"success"<<endl;
        else cout<<"fail"<<endl;
    }
    cout<<"HashTable content"<<endl;
    h.print();
    return 0;
}
