#include <bits/stdc++.h>
using namespace std;

class node
{
private:
    int value;
    node* next;
public:
    node(int v)
    {
        value=v;
        next=NULL;
    }
    node(int v,node *n)
    {
        value=v;
        next=n;
    }
    void set_value(int v)
    {
        value=v;
    }
    int get_value()
    {
        return this->value;
    }
    node* get_next()
    {
        return this->next;
    }

 friend class linked_list;
 };
class linked_list
{
    node * root;

public:
        linked_list()
        {
            root=NULL;
        }
        //always ask if list is empty does function works well
        void push_front(int x)//O(1)
        {
            node* temp=new node(x);
            temp->next=root;
            root=temp;
            //must dynamic allocated to be created in heap so pointer that points to node will be deleted it's local but node itself will not
        }
        void push_back(int x)//O(n)
        {
            if(root==NULL){
                root=new node(x,NULL);
            }
            else
            {
                node* traverse_ptr=root;
                while(traverse_ptr->next!=NULL)
                {
                    traverse_ptr=traverse_ptr->next;
                }
                traverse_ptr->next=new node(x,NULL);
            }
        }
        node* getRoot()
        {
            return root;
        }
        void print_list()
        {
            if(root==NULL);
            else
            {
                node* temp=root;//in order not to play wrong with root take a copy from root
                while(temp->next!=NULL)
                {
                    cout<<temp->value<<"--->";
                    temp=temp->next;
                }
                cout<<temp->value<<endl;
            }
        }
        int get_front()
        {
            if(root!=NULL)
                return root->value;
            return -1000;//any indication for that list is empty
        }
        void remove_front()
        {
            if(root!=NULL)
            {
                node* temp=root;
                root=root->next;
                delete temp;
            }
        }
        void remove_back()
        {
            //this if works well if there is at least 2 elements in list so we added 2nd condition
            if(root!=NULL&&root->next!=NULL)
            {
                node* temp=root;
                node* prev=root;
                while(temp->next!=NULL)
                {
                    prev=temp;
                    temp=temp->next;
                }
                delete temp;
                prev->next=NULL;
            }
            else if(root!=NULL)
            {
                delete root;
                root=NULL;
            }
        }
        void remove(int x)
        {
            if(root!=NULL&&root->value==x)
            {
                remove_front();
            }
            else if(root!=NULL)
            {
                node* traverse_ptr=root;
                while(traverse_ptr->next!=NULL&&traverse_ptr->next->value!=x)
                {
                    traverse_ptr=traverse_ptr->next;
                }
                //you need to delete if next!=NULL as you find node
                if(traverse_ptr->next!=NULL)
                {
                    node* temp=traverse_ptr->next;
                    traverse_ptr->next=traverse_ptr->next->next;
                    delete temp;
                }
            }
        }

};


void Q1_Selection_Sort(node * root)
{
    if(root==NULL)
        return;
    node * temp=root;
    while(temp->get_next()!=NULL)
    {
        node* temp2=temp->get_next();
        node* minNode=temp;
        while(temp2!=NULL)
        {
            if(temp2->get_value()<minNode->get_value())
            {
                minNode=temp2;
            }
            temp2=temp2->get_next();
        }
        //swap only content;
        int t=temp->get_value();
        temp->set_value(minNode->get_value());
        minNode->set_value(t);
        temp=temp->get_next();
    }
}
void Q2_bubble_sort(node* root)
{
    if(root==NULL||root->get_next()==NULL) return;
    node * endnode = NULL;
	bool swapped = false;
    do
    {
         swapped = false;
         node* temp=root;
         while(temp->get_next()!=endnode)
        {
         if(temp->get_value()>temp->get_next()->get_value())
            {
                int t = temp->get_value();
				temp->set_value(temp->get_next()->get_value());
				temp->get_next()->set_value(t);
				swapped = true;
            }
                temp=temp->get_next();
         }
         endnode=temp;
    }while(swapped&&endnode!=root);
}
bool Q3_equal(linked_list&  input1, linked_list& input2)
{
	node * root1 = input1.getRoot();
	node * root2 = input2.getRoot();
	while (root1 != NULL && root2 != NULL)
	{
		if (root1->get_value() == root2->get_value())
		{
			root1 = root1->get_next();
			root2 = root2->get_next();
		}
		else
			return false;
	}
	if (root1 != NULL || root2 != NULL)//can be done using size
		return false;
	else
		return true;

}

void Q4_print_reverse(node* root)
{
    if(root!=NULL)
    {
        Q4_print_reverse(root->get_next());//print remaining of Linked-list elements
        cout<<root->get_value()<<" ";//then print current node
    }
}
//this fn without going on linked list twice(we are not handling errors)
int Q5_Get_nth_element_from_end(node* root,int n)
{
    node* leading_ptr=root;
    for(int i=0;i<n;i++)//this will be difference between leading_ptr and following_ptr n steps so when leading_ptr comes to end(NULL) following comes to nth from end
    {
        leading_ptr=leading_ptr->get_next();
    }
    node* following_ptr=root;
    while(leading_ptr!=NULL)
    {
        following_ptr=following_ptr->get_next();
        leading_ptr=leading_ptr->get_next();
    }
    return following_ptr->get_value();
}
int Q6_get_middle(node* root)
{
    node* fast_ptr=root;
    node* slow_ptr=root;
    while(fast_ptr&&slow_ptr&&fast_ptr->get_next())
    {
        slow_ptr=slow_ptr->get_next();
        fast_ptr=fast_ptr->get_next()->get_next();
    }
    return slow_ptr->get_value();
}
/*------Testing_functions------*/
void test_print_reverse()
{
	linked_list l;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(10 - i);
	}
	l.print_list();
	Q4_print_reverse(l.getRoot());
}
void test_equal()
{
	linked_list s;
	linked_list m;
	linked_list g;
	cout << "Testing equal" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		s.push_back(i);
		m.push_back(i);
		g.push_back(i);
	}
	g.remove_back();
	g.push_back(10);
    s.print_list();
    g.print_list();
    m.print_list();
	cout << Q3_equal(s,g) << " should be 0" << endl;
	cout << Q3_equal(s,m) << " should be 1" << endl;
}

void test_selectionsort()
{
	linked_list l;
	for(size_t i = 0; i < 10; i++)
	{
		l.push_back(10 - i);
	}
	l.print_list();
	Q1_Selection_Sort(l.getRoot());
	l.print_list();
}
void test_bubblesort()
{
	linked_list l;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(10 -i);
	}
	l.print_list();
	Q2_bubble_sort(l.getRoot());
	l.print_list();
}
void test_get_nth_from_end()
{
	linked_list l;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(10 - i);
	}
	l.print_list();
	cout << "the 5th element from the end is " << Q5_Get_nth_element_from_end(l.getRoot(), 5)<<endl;
	cout << "5 should be printed"<<endl;
}
void test_get_middle_element()
{
	linked_list l;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(10 - i);
	}
	l.print_list();
	cout << "Middle Element -> " << Q6_get_middle(l.getRoot()) << endl;
	cout << "Should be 5" << endl;
	linked_list m;
	for (size_t i = 0; i < 11; i++)
	{
		m.push_back(11 - i);
	}
	m.print_list();
	cout << "Middle Element -> " << Q6_get_middle(m.getRoot()) << endl;
	cout << "Should be 6" << endl;
}
int main()
{
    //test_selectionsort();
    //test_bubblesort();
    //test_equal();
    //test_print_reverse();
    //test_get_nth_from_end();
    test_get_middle_element();
    return 0;
}
