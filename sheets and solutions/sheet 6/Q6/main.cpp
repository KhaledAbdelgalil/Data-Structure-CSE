#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<list>
#include<cmath>
using namespace std;

class student{
public: string firstName;
        string lastName;
        int degree;

};
class hashTable{
public: list<student>* Table;
        int table_size;

        hashTable(int max_)
        {
            table_size=max_;
            Table=new list<student>[max_];
        }
        int hashFunction(student object)
        {
            int hashing=0;
            for(int i=0;i<object.firstName.size();i++)
            {
                hashing+=int(object.firstName[i]);
            }
            return hashing%table_size;

        }
        void insert(student element)
        {
            int index=hashFunction(element);
            Table[index].push_back(element);
        }
        student search(string firstName)
        {
            int hashing=0;
            for(int i=0;i<firstName.size();i++)
            {
                hashing+=int(firstName[i]);
            }
            hashing=hashing%table_size;

            for(list<student>::iterator it=Table[hashing].begin();it!=Table[hashing].end();it++)
            {
                student temp=*it;
                if(temp.firstName==firstName) {
                    return temp;
                }
            }
        }

};




int main()
{

    int n;
    hashTable h(10);

    cout<<"enter number of students"<<endl;
    cin>>n;
    string s;
    int d;
    for(int i=0;i<n;i++)
    {
        student temp;
        cin>>s;
        temp.firstName=s;
        cin>>s;
        temp.lastName=s;
        cin>>d;
        temp.degree=d;
        h.insert(temp);
    }
    for(int i=0;i<h.table_size;i++)
    {
        cout<<"index "<<i<<" has "<<h.Table[i].size()<<" students"<<endl;
        for(list<student>::iterator it=h.Table[i].begin();it!=h.Table[i].end();it++)
        {
            student temp=*it;
            cout<<temp.firstName<<" "<<temp.lastName<<" got "<<temp.degree<<endl;
        }
        cout<<"----------"<<endl;
    }
    cout<<"enter name for searching"<<endl;
    cin>>s;
    student t=h.search(s);

    cout<<t.firstName<<" "<<t.lastName<<" got "<<t.degree<<endl;

    return 0;
}
