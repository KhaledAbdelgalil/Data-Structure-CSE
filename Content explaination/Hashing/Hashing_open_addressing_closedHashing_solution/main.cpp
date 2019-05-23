#include <iostream>
using namespace std;

class hashTable_LinearProbe{
public: int* Table;
        int max_size;
        int current_size;

        hashTable_LinearProbe(int max_)
        {
            max_size=max_;
            Table=new int[max_];
            for(int i=0;i<max_;i++)
            {
                Table[i]=-1;
            }
            current_size=0;
        }
        int hashFunction1(int element)
        {
            return element%max_size;
        }
        int hashFunction2(int element,int i)
        {
            return (element+i)%max_size;//quadratic probing is same but fn is (element+i^2)%max_size
        }
        bool insert_hashing(int element)
        {
            if(current_size==max_size) return 0;
            int index=hashFunction1(element);
            if(Table[index]==-1)
                Table[index]=element;
            else
            {
                int i=1;
                int index2=hashFunction2(element,i);
                while(Table[index2]!=-1)
                {
                    i++;
                    index2=hashFunction2(element,i);
                }
                Table[index2]=element;
            }
            current_size++;
            return 1;
        }
        bool delete_hashing(int element)
        {
            if(current_size==0) return 0;
            int index=hashFunction1(element);
            if(Table[index]==element)
                {
                Table[index]=-1;
                current_size--;
                return 1;
                }
            else
            {
                int i=1;
                int index2=hashFunction2(element,i);
                while(Table[index2]!=element)
                {
                    i++;
                    index2=hashFunction2(element,i);
                    if(Table[index2]==-1) return 0;
                }
                Table[index2]=-1;
            }
            current_size--;
            return 1;
        }

};

int main()
{
    int n;
    cin>>n;
    int x;
    hashTable_LinearProbe h(10);
    for(int i=0;i<n;i++)
    {
        cin>>x;
       if(h.insert_hashing(x)) cout<<"insertion happened"<<endl;
       else cout<<"size is max no insertion"<<endl;
    }
    cout<<"before deletion"<<endl;
    for(int i=0;i<h.max_size;i++)
    {
        if(h.Table[i]==-1) continue;

        cout<<h.Table[i]<<" has hashing index "<<i<<endl;
    }
    cout<<"enter number of elements you want to delete"<<endl;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"element"<<i+1<<" has key :"<<endl;
        cin>>x;
        if(h.delete_hashing(x))
        {
            cout<<"success"<<endl;
        }
        else cout<<"no element found with this key"<<endl;
    }
    cout<<"after deletion"<<endl;
     for(int i=0;i<h.max_size;i++)
    {
        if(h.Table[i]==-1) continue;
        cout<<h.Table[i]<<" has hashing index "<<i<<endl;

    }

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x;
       if(h.insert_hashing(x)) cout<<"insertion happened"<<endl;
       else cout<<"size is max no insertion"<<endl;
    }
    cout<<"after 2nd insertion"<<endl;
    for(int i=0;i<h.max_size;i++)
    {
        if(h.Table[i]==-1) continue;

        cout<<h.Table[i]<<" has hashing index "<<i<<endl;
    }
    return 0;
}
