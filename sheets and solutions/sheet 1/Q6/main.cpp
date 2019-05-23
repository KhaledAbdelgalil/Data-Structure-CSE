#include <bits/stdc++.h>

using namespace std;
class book{
private: pair<string,string>* email_name;
         int size_used;
public:
    book(int n)
    {
        email_name=new pair<string,string>[n];
        size_used=0;
    }
    pair<string,string> get(int index)
    {
        return email_name[index];
    }
    void set(string email,string name)
    {
        email_name[size_used].first=email;
        email_name[size_used].second=name;
        size_used++;
    }
    void print_all()
    {
        for(int i=0;i<size_used;i++)
        {
            cout<<"name: "<<email_name[i].second<<" has email: "<<email_name[i].first<<endl;
        }
    }


};
int main()
{
    book book1(10);
    book1.set("khaled@gmail.com","khaled");
    book1.set("fateh@gmail.com","fateh");
    book1.set("salma@gmail.com","salma");
    book1.print_all();
    cout<<endl;
    book1.set("marwan@gmail.com","marwan");
    book1.print_all();



    return 0;
}
