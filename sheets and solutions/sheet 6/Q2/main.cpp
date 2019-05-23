#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<list>
#include<cmath>
using namespace std;

class hashTable{
public: list<int>* Table;
        int max_size;
        char part;

        hashTable(int max_,char flag)
        {
            max_size=max_;
            Table=new list<int>[max_];
            part=flag;
        }
        int hashFunction(int element)
        {
            if(part=='a')
            return element%max_size;
            else if(part=='b') return (element*element)%max_size;
            else if(part=='c') return (int(sqrt(element)))%max_size;
            else if(part=='d') return element%3;
            else return rand()%max_size;
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
                cout<<"index "<<i<<" has "<<Table[i].size()<<" elements "<<endl;
            }
        }
};

void Q2_a_solution()
{
    hashTable h(10,'a');
    for(int i=200;i<300;i++)
        h.insert(i);
    h.print();
}
void Q2_b_solution()
{
    hashTable h(10,'b');
    for(int i=200;i<300;i++)
        h.insert(i);
    h.print();
}
void Q2_c_solution()
{
    hashTable h(10,'c');
    for(int i=200;i<300;i++)
        h.insert(i);
    h.print();
}
void Q2_d_solution()
{
    hashTable h(10,'d');
    for(int i=200;i<300;i++)
        h.insert(i);
    h.print();
}
void Q2_e_solution()
{
    hashTable h(10,'e');
    for(int i=200;i<300;i++)
        h.insert(i);
    h.print();
}


int main()
{
    //Q2_a_solution();
    //Q2_b_solution();//x=c*m+r x^2=(c2m2+2cmr+r2);x^2%m=r2%m=(x%m)^2%m;
    //Q2_c_solution();
    //Q2_d_solution();
    Q2_e_solution();
    return 0;
}
