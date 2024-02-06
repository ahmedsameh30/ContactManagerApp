#include "Contact.h"
#include<bits/stdc++.h>
#include "Users.h"
#include "Phone.h"
#include "Email.h"

using namespace std;

Contact::Contact()
{

}

int Contact::charArr_to_int(string t)
{
    int num = 0,n;
    for(int i = 0;i < (int)t.size();i++){
        n = t[i] - 48;
        num = (num*10) + n;
    }
    return num;
}
void Contact::add_contact()
{
    cout<<"----------------------------------------\n";
    cout<<" 1) Add a new contact\n"
        <<" 2) Add an extra phone number to a contact\n"
        <<" 3) Add an extra mail to a contact\n"
        <<" 0) Exit"<<endl;
    int n; string Id;
    cout<<" Enter your choice : "; cin>>n;
    switch(n)
    {
    case 1 :
        u._add_contact();
        break;
    case 2 :
        {
            cout<<" Enter contact id : "; cin>>Id;
            u.add_extra_phon_or_mail(n,Id);
        }
        break;
    case 3 :
        {
            cout<<" Enter contact id : "; cin>>Id;
            u.add_extra_phon_or_mail(n,Id);
        }
        break;
    case 0 :
        break;
    }
}
void Contact::edit_contact()
{
    string id;
    cout<<"----------------------------------------\n";
    cout<<" Enter contact id : ";cin>>id;
    u._edit_contact(id);
}
void Contact::search_for_contact()
{
    u._search();
}
void Contact::delete_contact()
{
    cout<<"----------------------------------------\n";
    cout<<" 1) Delete a contact\n"
        <<" 2) Delete specific phone number from a contact\n"
        <<" 3) Delete specific mail from a contact\n"
        <<" 0) Exit"<<endl;
    int n; string Id;
    cout<<" Enter your choice : "; cin>>n;
    cout<<" Enter contact id : "; cin>>Id;
    switch(n)
    {
    case 1 :
        u._delete_contact(Id);
        break;
    case 2 :
        u.delete_certain_phone(Id);
        break;
    case 3 :
        u.delete_certain_mail(Id);
        break;
    case 0 :
        break;
    }
    cout<<" Deleted successfully.."<<endl;
}
void Contact::how_many_contacts()
{
    cout<<" There are "<<u.no_of_contacts()<<" contacts"<<endl;
}
void Contact::print_all_contacts()
{
    u.display_all_contacts();
}
Contact::~Contact()
{
    //dtor
}
