#include "Users.h"
#include "Phone.h"
#include "Email.h"
#include<bits/stdc++.h>
using namespace std;


Users::Users():id(0),name(""),gender(""),city(""),address("")
{

}
Users::Users(const Users& user)
{
    this->name = user.name;
    this->gender = user.gender;
    this->city = user.city;
    this->address = user.address;
}
void Users::_add_contact()
{
    cout<<"----------------------------------------\n";
    cout<<" Enter contact id : "; cin>>id;

    cout<<" Enter the name : ";
    cin.ignore(); getline(cin,name);

    cout<<" Enter gender : ";
    getline(cin,gender);

    cout<<" Enter the city : ";
    getline(cin,city);

    cout<<" Enter the address : ";
    getline(cin,address);

    p.add_phone_details(id);
    e.add_mail(id);

    contact.open("contacts.txt",ios::app);
    contact<<id<<'|'<<name<<'|'<<gender<<'|'<<city<<'|'<<address<<'\n';
    contact.close();
}
void Users::add_extra_phon_or_mail(int n,string ID)
{
    if(n == 2){
        p.add_extra_phone(ID);
    }
    else if(n == 3){
        e.add_extra_mail(ID);
    }
}
void Users::_edit_contact(string ID)
{
    cout<<"\n----------------------------------------\n";
    cout<<" What would you to edit ?\n";
    cout<<" 1. Name\n"
        <<" 2. Gender\n"
        <<" 3. City\n"
        <<" 4. Address\n"
        <<" 5. Phone number\n"
        <<" 6. Email\n"
        <<" 0. Exit"<<endl;
    int n;
    cout<<" Enter your choice : "; cin>>n;
    if(n == 5)
        p.edit_phone(ID);
    else if(n == 6)
        e.edit_mail(ID);
    else if(n != 0){
        contact.open("contacts.txt",ios::in);
        temp.open("temp.txt",ios::out);
        while(!contact.eof()){
            contact.getline(_id,5,'|');
            contact.getline(_name,50,'|');
            contact.getline(_gender,8,'|');
            contact.getline(_city,30,'|');
            contact.getline(_address,50);

            if(ID == _id){
                switch(n)
                {
                case 1 :
                    {
                        cout<<" Enter the new name : "; cin.ignore(); cin.getline(_name,50);
                    }
                    break;
                case 2 :
                    {
                        cout<<" Enter the gender after editing : "; cin.ignore(); cin.getline(_gender,8);
                    }
                    break;
                case 3 :
                    {
                        cout<<" Enter the city after editing : "; cin.ignore(); cin.getline(_city,30);
                    }
                    break;
                case 4 :
                    {
                        cout<<" Enter the address after editing : "; cin.ignore(); cin.getline(_address,50);
                    }
                    break;
                }
            }
            temp<<_id<<'|'<<_name<<'|'<<_gender<<'|'<<_city<<'|'<<_address<<'\n';
        }
        contact.clear();
        contact.close();
        temp.close();

        contact.open("contacts.txt",ios::out);
        temp.open("temp.txt",ios::in);
        while(!temp.eof()){
            temp.getline(_id,5,'|');
            temp.getline(_name,50,'|');
            temp.getline(_gender,8,'|');
            temp.getline(_city,30,'|');
            temp.getline(_address,50);

            contact<<_id<<'|'<<_name<<'|'<<_gender<<'|'<<_city<<'|'<<_address<<'\n';
        }
        contact.close();
        temp.close();
        remove("temp.txt");
    }
}
void Users::search_by_name()
{
    int c = 0;
    string name_;
    cout<<"\n Enter the name : "; cin>>name_;
    contact.open("contacts.txt",ios::in);
    while(!contact.eof()){
        contact.getline(_id,5,'|');
        contact.getline(_name,50,'|');
        contact.getline(_gender,8,'|');
        contact.getline(_city,30,'|');
        contact.getline(_address,50);

        string t = _name;
        if(t.find(name_) != string::npos){
            c++;
        }
    }
    cout<<" There are "<<c<<" contacts with this name\n"<<endl;
    contact.close();
}
void Users::search_by_contact_id()
{
    string id_;
    bool f = false;
    cout<<"\n Enter contact id : "; cin>>id_;
    contact.open("contacts.txt",ios::in);
    while(!contact.eof()){
        contact.getline(_id,5,'|');
        contact.getline(_name,50,'|');
        contact.getline(_gender,8,'|');
        contact.getline(_city,30,'|');
        contact.getline(_address,50);

        string s = _id;
        if(id_ == _id){
            cout<<" Found.."<<endl;
            f = true; break;
        }
        else
            f = false;
    }
    if(!f)
        cout<<" Not found ! \n"<<endl;
    contact.close();
}
void Users::_search()
{
    int n;
    cout<<"----------------------------------------\n";
    cout<<" Search by :- "<<endl;
    cout<<" 1. Contact Id\n"
        <<" 2. Name \n"
        <<" 3. Phone number\n"<<endl;
    cout<<" Enter your choice : "; cin>>n;
    switch(n)
    {
    case 1 :
        search_by_contact_id();
        break;
    case 2 :
        search_by_name();
        break;
    case 3 :
        p.search_();
        break;
    }
}
void Users::_delete_contact(string ID)
{
    contact.open("contacts.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!contact.eof()){
        contact.getline(_id,5,'|');
        contact.getline(_name,50,'|');
        contact.getline(_gender,8,'|');
        contact.getline(_city,30,'|');
        contact.getline(_address,50);

        string s = _id;
        if(s == ID){
        }
        else{
            temp<<_id<<'|'<<_name<<'|'<<_gender<<'|'<<_city<<'|'<<_address<<'\n';
        }
    }
    contact.close();
    temp.close();

    contact.open("contacts.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_name,50,'|');
        temp.getline(_gender,8,'|');
        temp.getline(_city,30,'|');
        temp.getline(_address,50);

        contact<<_id<<'|'<<_name<<'|'<<_gender<<'|'<<_city<<'|'<<_address<<'\n';
    }
    contact.close();
    temp.close();
    remove("temp.txt");
    p.delete_all(ID);
    e.delete_all(ID);
}
void Users::delete_certain_phone(string ID)
{
    p.delete_specific_phone(ID);
}
void Users::delete_certain_mail(string ID)
{
    e.delete_specific_mail(ID);
}
int Users::no_of_contacts()
{
    int c = 0;
    contact.open("contacts.txt",ios::in);
    while(!contact.eof()){
        contact.getline(_id,5,'|');
        contact.getline(_name,50,'|');
        contact.getline(_gender,8,'|');
        contact.getline(_city,30,'|');
        contact.getline(_address,50);

        string s = _id;
        if(s.size() > 0)
            c++;
    }
    contact.close();
    return c;
}
void Users::display_all_contacts()
{
    cout<<"----------------------------------------\n";
    contact.open("contacts.txt",ios::in);
    while(!contact.eof()){
        contact.getline(_id,5,'|');
        contact.getline(_name,50,'|');
        contact.getline(_gender,8,'|');
        contact.getline(_city,30,'|');
        contact.getline(_address,50);

        string s = _id;
        if(s.size() == 0)
            break;
        cout<<" Contact id :- "<<_id<<"\t "<<" The name :- "<<_name<<endl;
        cout<<" Gender :- "<<_gender<<"\t\t "<<" The city :- "<<_city<<endl;
        cout<<" The address :- "<<_address<<endl;
        cout<<"\n **The total phone numbers for this contact :- ";
        p.print(_id);
        cout<<"\n\n **The total mails for this contact :- ";
        e.print(_id);
        cout<<"\n----------------------------------------\n"<<endl;
    }
    contact.close();
}
Users::~Users()
{

}
