#include<iostream>
#include "Contact.h"

using namespace std;

void contact_manager()
{
    Contact c;
    bool f = true;
    while(f){
        cout<<"========================================"<<endl;
        cout<<" Contact menu :- "<<endl;
        cout<<" 1. Add contact\n"
            <<" 2. Edit contact info\n"
            <<" 3. Search for contact\n"
            <<" 4. Delete a contact\n"
            <<" 5. Print all contacts\n"
            <<" 6. Number of contacts ?\n"
            <<" 0. Exit"<<endl;
        int n;
        cout<<"\n Enter your choice : "; cin>>n;
        switch(n)
        {
            case 1 :
                c.add_contact();
                break;
            case 2 :
                c.edit_contact();
                break;
            case 3 :
                c.search_for_contact();
                break;
            case 4 :
                c.delete_contact();
                break;
            case 5 :
                c.print_all_contacts();
                break;
            case 6 :
                c.how_many_contacts();
                break;
            case 0 :
                f = false;
                break;
            default :
                cout<<"\n wrong choice ! .. Choose again"<<endl;
        }
    }
}
int main()
{
    contact_manager();
    return 0;
}
