#include <iostream>
#include<vector>
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


class hashTable_LinearProbe1{
public: int* Table;
        int max_size;
        int current_size;

        hashTable_LinearProbe1(int max_)
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
        void print()
        {
            for(int i=0;i<max_size;i++)
            {
                if(Table[i]!=-1)
                {
                    cout<<"element: "<<Table[i]<<" has hashing index: "<<i<<endl;
                }
            }
        }

};




class hashTable_LinearProbe2{
public: int* Table;
        int max_size;
        int current_size;

        hashTable_LinearProbe2(int max_)
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
            return (element+3*i)%max_size;//quadratic probing is same but fn is (element+i^2)%max_size
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
        void print()
        {
            for(int i=0;i<max_size;i++)
            {
                if(Table[i]!=-1)
                {
                    cout<<"element: "<<Table[i]<<" has hashing index: "<<i<<endl;
                }
            }
        }

};

void Q1_a_Bad_solution()
{
    int n,x;
    cin>>n;
    vector<int>directMappingBad(3001,0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        directMappingBad[x]=x;
    }
    for(int i=0;i<3001;i++)
    {
        if(directMappingBad[i]!=0)
        {
            cout<<directMappingBad[i]<<" is mapped to "<<i<<endl;
        }
    }
    cout<<"others is wasted Memory so bad solution 3001 elements is reserved we used "<<n<<" elements only "<<endl;
}
void Q1_a_better_Solution()
{
    //range is between 400-3000 so map from 0 to 2600//more better than directMapping on 3001 elements but still wasted memory
     int n,x;
    cin>>n;
    vector<int>directMapping(2601,0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        directMapping[x-400]=x;
    }
    for(int i=0;i<3001;i++)
    {
        if(directMapping[i]!=0)
        {
            cout<<directMapping[i]<<" is mapped to "<<i<<endl;
        }
    }
    cout<<"others is wasted Memory"<<endl;
}

void Q1_b_Solution()
{
    int n,x;
    cin>>n;
    hashTable h7(7);
    for(int i=0;i<n;i++)
        cin>>x,h7.insert(x);
    h7.print();
}
void Q1_c_Solution()
{
    int n,x;
    cin>>n;
    hashTable h11(11);
    for(int i=0;i<n;i++)
        cin>>x,h11.insert(x);
    h11.print();
}

void Q1_d_Solution()
{
    hashTable_LinearProbe1 h(40);
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        h.insert_hashing(x);
    }
    h.print();
}

void Q1_e_Solution()
{
    hashTable_LinearProbe2 h(40);
    int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        h.insert_hashing(x);
    }
    h.print();
}


int main()
{
    //Q1_a_Bad_solution();
    //Q1_a_better_Solution();
    //Q1_b_Solution();
    //Q1_c_Solution();
    //Q1_d_Solution();
    Q1_e_Solution();
    return 0;
}
