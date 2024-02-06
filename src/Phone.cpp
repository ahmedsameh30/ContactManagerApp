#include "Phone.h"
#include<bits/stdc++.h>
#include "Contact.h"
using namespace std;

Phone::Phone():no_of_phones(0),phone(""),type("")
{

}
Phone::Phone(const Phone& ph)
{
    this->no_of_phones = ph.no_of_phones;
    this->phone = ph.phone;
    this->type = ph.type;
}
string Phone::check_phone_type(string &t)
{
    string s = t.substr(0,3);
    if(s == "010")
        return "Vodafone";
    else if(s == "011")
        return "Etisalat";
    else if(s == "012")
        return "Orange";
    else
        return "We";
}
void Phone::update_no_of_phones(char x,string ID)
{
    noph.open("number of phones.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!noph.eof()){
        noph.getline(_id,5,'|');
        noph.getline(_no_of_phones,3);

        if(_id == ID){
            string s = _no_of_phones;
            int n = Contact::charArr_to_int(s);
            if(x == '+')
                n++;
            else
                n--;
            temp<<_id<<'|'<<n<<'\n';
        }
        else
            temp<<_id<<'|'<<_no_of_phones<<'\n';
    }
    noph.close();
    temp.close();

    noph.open("number of phones.txt",ios::out);
    temp.open("temp.txt",ios::in);
    noph.clear();
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_no_of_phones,3);

        noph<<_id<<'|'<<_no_of_phones<<'\n';
    }
    noph.close();
    temp.close();
    remove("temp.txt");
}
void Phone::add_phone_details(int id)
{
    cout<<" Enter phone number : "; cin>>phone;
    no_of_phones++;
    type = check_phone_type(phone);

    noph.open("number of phones.txt",ios::app);
    noph<<id<<'|'<<no_of_phones<<'\n';
    noph.close();

    phon.open("phone.txt",ios::app);
    phon<<id<<'|'<<phone<<'|'<<type<<'\n';
    phon.close();
}
void Phone::add_extra_phone(string ID)
{
    cout<<"\n Enter phone number : "; cin>>phone;
    type = check_phone_type(phone);
    phon.open("phone.txt",ios::app);
    phon<<ID<<'|'<<phone<<'|'<<type<<'\n';
    phon.close();

    update_no_of_phones('+',ID);
}
void Phone::edit_phone(string ID)
{
    phon.open("phone.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!phon.eof()){
        phon.getline(_id,5,'|');
        phon.getline(_phone,13,'|');
        phon.getline(_type,20);

        if(ID == _id){
            vp.push_back(make_pair(_phone,_type));
        }
        else
            temp<<_id<<'|'<<_phone<<'|'<<_type<<'\n';

    }
    phon.clear();
    phon.close();
    temp.close();

    string s;
    if(vp.size() == 0)
        cout<<" This id you entered may be wrong or this contact has no phone numbers yet !"<<endl;
    else if(vp.size() == 1){
        cout<<" this user has "<<1<<" phone number which is "<<vp[0].first<<endl;
        cout<<" Are you sure you want to edit it ? [yes/no] : "; cin>>s;
        if(s == "yes"){
            cout<<" Enter the edited phone number : "; cin>>s;
            vp[0].second = check_phone_type(s);
            vp[0].first = s;
        }
    }
    else{
        cout<<"\n There are more than phone number for this contact..\n"<<endl;
        for(int i = 0;i < (int)vp.size();i++){
            cout<<" "<<i+1<<".  "<<vp[i].first<<endl;
        }
        int n;
        cout<<" Which phone number you want to edit ? "; cin>>n;
        cout<<" Enter the edited phone number : "; cin>>s;
        vp[n-1].second = check_phone_type(s);
        vp[n-1].first = s;
    }

    phon.open("phone.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_phone,13,'|');
        temp.getline(_type,20);

        phon<<_id<<'|'<<_phone<<'|'<<_type<<'\n';
    }
    for(int i = 0;i < (int)vp.size();i++){
        phon<<ID<<'|'<<vp[i].first<<'|'<<vp[i].second<<'\n';
    }
    phon.close();
    temp.close();
    remove("temp.txt");
    vp.clear();
}
void Phone::search_()
{
    string ph; bool f = false;
    cout<<" Enter phone number : "; cin>>ph;
    phon.open("phone.txt",ios::in);
    while(!phon.eof()){
        phon.getline(_id,5,'|');
        phon.getline(_phone,13,'|');
        phon.getline(_type,20);

        if(ph == _phone){
            cout<<" Found.."<<endl;
            f = true; break;
        }
        else
            f = false;
    }
    phon.close();
    if(!f)
        cout<<" Not found !"<<endl;
}
void Phone::delete_specific_phone(string ID)
{
    phon.open("phone.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!phon.eof()){
        phon.getline(_id,5,'|');
        phon.getline(_phone,13,'|');
        phon.getline(_type,20);

        if(ID == _id){
            vp.push_back(make_pair(_phone,_type));
        }
        else
            temp<<_id<<'|'<<_phone<<'|'<<_type<<'\n';

    }
    phon.clear();
    phon.close();
    temp.close();

    string s;
    if(vp.size() == 0)
        cout<<" This id you entered may be wrong or this contact has no phone numbers yet !"<<endl;
    else if(vp.size() == 1){
        cout<<" this user has "<<1<<" phone number which is "<<vp[0].first<<endl;
        cout<<" Are you sure you want to delete it ? [yes/no] : "; cin>>s;
        phon.open("phone.txt",ios::out);
        temp.open("temp.txt",ios::in);
        if(s == "yes"){
            while(!temp.eof()){
               temp.getline(_id,5,'|');
               temp.getline(_phone,13,'|');
               temp.getline(_type,20);

               phon<<_id<<'|'<<_phone<<'|'<<_type<<'\n';
            }
        }
        else{
            while(!temp.eof()){
               temp.getline(_id,5,'|');
               temp.getline(_phone,13,'|');
               temp.getline(_type,20);

               phon<<_id<<'|'<<_phone<<'|'<<_type<<'\n';
            }
            phon<<ID<<'|'<<vp[0].first<<'|'<<vp[0].second<<'\n';
        }
        phon.close();
        temp.close();
        remove("temp.txt");
        vp.clear();
    }
    else{
        cout<<" There are more than phone number for this contact..\n"<<endl;
        for(int i = 0;i < (int)vp.size();i++){
            cout<<" "<<i+1<<".  "<<vp[i].first<<endl;
        }
        int n;
        cout<<" Which phone number you want to delete ? [0 to undo] "; cin>>n;
        phon.open("phone.txt",ios::out);
        temp.open("temp.txt",ios::in);
        phon.clear();
        while(!temp.eof()){
            temp.getline(_id,5,'|');
            temp.getline(_phone,13,'|');
            temp.getline(_type,20);

            phon<<_id<<'|'<<_phone<<'|'<<_type<<'\n';
        }
        if(n != 0){
            for(int i = 0;i < (int)vp.size();i++){
                if(i != n-1)
                    phon<<ID<<'|'<<vp[i].first<<'|'<<vp[i].second<<'\n';
            }
        }
        else{
            for(int i = 0;i < (int)vp.size();i++)
                phon<<ID<<'|'<<vp[i].first<<'|'<<vp[i].second<<'\n';
        }
        phon.close();
        temp.close();
        remove("temp.txt");
        vp.clear();
    }

    update_no_of_phones('-',ID);
}
void Phone::delete_all(string ID)
{
    phon.open("phone.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!phon.eof()){
        phon.getline(_id,5,'|');
        phon.getline(_phone,13,'|');
        phon.getline(_type,20);

        if(_id != ID){
            temp<<_id<<'|'<<_phone<<'|'<<_type<<'\n';
        }
    }
    phon.clear();
    phon.close();
    temp.close();

    phon.open("phone.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_phone,13,'|');
        temp.getline(_type,20);

        phon<<_id<<'|'<<_phone<<'|'<<_type<<'\n';
    }
    phon.close();
    temp.close();
    remove("temp.txt");

    noph.open("number of phones.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!noph.eof()){
        noph.getline(_id,5,'|');
        noph.getline(_no_of_phones,3);

        if(_id != ID){
            temp<<_id<<'|'<<_no_of_phones<<'\n';
        }
    }
    noph.close();
    temp.close();

    noph.open("number of phones.txt",ios::out);
    temp.open("temp.txt",ios::in);
    noph.clear();
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_no_of_phones,3);

        noph<<_id<<'|'<<_no_of_phones<<'\n';
    }
    noph.close();
    temp.close();
    remove("temp.txt");
}
void Phone::print(string ID)
{
    phon.open("phone.txt",ios::in);
    cout<<"\n";
    while(!phon.eof()){
        phon.getline(_id,5,'|');
        phon.getline(_phone,13,'|');
        phon.getline(_type,20);

        string s = _id;
        if(s.size() == 0)
            break;
        if(s == ID){
            cout<<"\n Phone : "<<_phone<<"\t  The type : "<<_type;
        }
    }
    phon.close();
}
Phone::~Phone()
{
    //dtor
}
