#include "Email.h"
#include "Contact.h"
#include<bits/stdc++.h>

using namespace std;

Email::Email():no_of_mails(0),email(""),type("")
{

}
Email::Email(const Email& e)
{
    this->no_of_mails = e.no_of_mails;
    this->email = e.email;
    this->type = e.type;
}
string Email::check_mail_type(string& t)
{
    if(t.find("@gmail.com") != string::npos)
        return "Google mail";
    else if(t.find("@yahoo.com") != string::npos)
        return "Yahoo mail";
}
void Email::update_no_of_phones(char x,string ID)
{
    nom.open("number of mails.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!nom.eof()){
        nom.getline(_id,5,'|');
        nom.getline(_no_of_mails,3);

        if(_id == ID){
            string s = _no_of_mails;
            int n = Contact::charArr_to_int(s);
            if(x == '+')
                n++;
            else
                n--;
            temp<<_id<<'|'<<n<<'\n';
        }
        else
            temp<<_id<<'|'<<_no_of_mails<<'\n';
    }
    nom.close();
    temp.close();

    nom.open("number of mails.txt",ios::out);
    temp.open("temp.txt",ios::in);
    nom.clear();
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_no_of_mails,3);

        nom<<_id<<'|'<<_no_of_mails<<'\n';
    }
    nom.close();
    temp.close();
    remove("temp.txt");
}
void Email::add_mail(int id)
{
    cout<<" Enter the E-mail : "; cin>>email;
    no_of_mails++;
    type = check_mail_type(email);
    mail.open("email.txt",ios::app);
    mail<<id<<'|'<<email<<'|'<<type<<'\n';
    mail.close();

    nom.open("number of mails.txt",ios::app);
    nom<<id<<'|'<<no_of_mails<<'\n';
    nom.close();
}
void Email::add_extra_mail(string ID)
{
    cout<<" Enter the E-mail : "; cin>>email;
    type = check_mail_type(email);
    mail.open("email.txt",ios::app);
    mail<<ID<<'|'<<email<<'|'<<type<<'\n';
    mail.close();

    update_no_of_phones('+',ID);
}
void Email::edit_mail(string ID)
{
    mail.open("email.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!mail.eof()){
        mail.getline(_id,5,'|');
        mail.getline(_mail,60,'|');
        mail.getline(_type,30);

        if(ID == _id){
            vp.push_back(make_pair(_mail,_type));
        }
        else
            temp<<_id<<'|'<<_mail<<'|'<<_type<<'\n';

    }
    mail.clear();
    mail.close();
    temp.close();

    string s;
    if(vp.size() == 0)
        cout<<" This id you entered may be wrong or this contact has no e-mails yet !"<<endl;
    else if(vp.size() == 1){
        cout<<" this user has "<<1<<" mail which is "<<vp[0].first<<endl;
        cout<<" Are you sure you want to edit it ? [yes/no] : "; cin>>s;
        if(s == "yes"){
            cout<<" Enter the edited mail : "; cin>>s;
            vp[0].second = check_mail_type(s);
            vp[0].first = s;
        }
    }
    else{
        cout<<" There are more than mail for this contact..\n"<<endl;
        for(int i = 0;i < (int)vp.size();i++){
            cout<<" "<<i+1<<".  "<<vp[i].first<<endl;
        }
        int n;
        cout<<" Which mail you want to edit ? [0 to undo]"; cin>>n;
        if(n != 0){
            cout<<" Enter the edited mail : "; cin>>s;
            vp[n-1].second = check_mail_type(s);
            vp[n-1].first = s;
        }
    }

    mail.open("email.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_mail,60,'|');
        temp.getline(_type,30);

        mail<<_id<<'|'<<_mail<<'|'<<_type<<'\n';
    }
    for(int i = 0;i < (int)vp.size();i++){
        mail<<ID<<'|'<<vp[i].first<<'|'<<vp[i].second<<'\n';
    }
    mail.close();
    temp.close();
    remove("temp.txt");
    vp.clear();
}
void Email::delete_specific_mail(string ID)
{
    mail.open("email.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!mail.eof()){
        mail.getline(_id,5,'|');
        mail.getline(_mail,60,'|');
        mail.getline(_type,30);

        if(ID == _id){
            vp.push_back(make_pair(_mail,_type));
        }
        else
            temp<<_id<<'|'<<_mail<<'|'<<_type<<'\n';

    }
    mail.clear();
    mail.close();
    temp.close();

    string s;
    if(vp.size() == 0)
        cout<<" This id you entered may be wrong or this contact has no e-mails yet !"<<endl;
    else if(vp.size() == 1){
        cout<<" this user has "<<1<<" mail which is "<<vp[0].first<<endl;
        cout<<" Are you sure you want to delete it ? [yes/no] : "; cin>>s;
        mail.open("email.txt",ios::out);
        temp.open("temp.txt",ios::in);
        if(s == "yes"){
            while(!temp.eof()){
               temp.getline(_id,5,'|');
               temp.getline(_mail,60,'|');
               temp.getline(_type,30);

               mail<<_id<<'|'<<_mail<<'|'<<_type<<'\n';
            }
        }
        else{
            while(!temp.eof()){
               temp.getline(_id,5,'|');
               temp.getline(_mail,60,'|');
               temp.getline(_type,30);

               mail<<_id<<'|'<<_mail<<'|'<<_type<<'\n';
            }
            mail<<ID<<'|'<<vp[0].first<<'|'<<vp[0].second<<'\n';
        }
        mail.close();
        temp.close();
        remove("temp.txt");
        vp.clear();
    }
    else{
        cout<<" There are more than mail for this contact..\n"<<endl;
        for(int i = 0;i < (int)vp.size();i++){
            cout<<" "<<i+1<<".  "<<vp[i].first<<endl;
        }
        int n;
        cout<<" Which mail you want to delete ? [0 to undo] "; cin>>n;
        mail.open("email.txt",ios::out);
        temp.open("temp.txt",ios::in);
        mail.clear();
        while(!temp.eof()){
            temp.getline(_id,5,'|');
            temp.getline(_mail,60,'|');
            temp.getline(_type,30);

            mail<<_id<<'|'<<_mail<<'|'<<_type<<'\n';
        }
        if(n != 0){
            for(int i = 0;i < (int)vp.size();i++){
                if(i != n-1)
                    mail<<ID<<'|'<<vp[i].first<<'|'<<vp[i].second<<'\n';
            }
        }
        else{
            for(int i = 0;i < (int)vp.size();i++)
                mail<<ID<<'|'<<vp[i].first<<'|'<<vp[i].second<<'\n';
        }
        mail.close();
        temp.close();
        remove("temp.txt");
        vp.clear();
    }

    update_no_of_phones('-',ID);
}
void Email::delete_all(string ID)
{
    mail.open("email.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!mail.eof()){
        mail.getline(_id,5,'|');
        mail.getline(_mail,60,'|');
        mail.getline(_type,30);

        if(_id != ID){
            temp<<_id<<'|'<<_mail<<'|'<<_type<<'\n';
        }
    }
    mail.clear();
    mail.close();
    temp.close();

    mail.open("email.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_mail,60,'|');
        temp.getline(_type,30);

        mail<<_id<<'|'<<_mail<<'|'<<_type<<'\n';
    }
    mail.close();
    temp.close();
    remove("temp.txt");

    nom.open("number of mails.txt",ios::in);
    temp.open("temp.txt",ios::out);
    while(!nom.eof()){
        nom.getline(_id,5,'|');
        nom.getline(_no_of_mails,3);

        if(_id != ID){
            temp<<_id<<'|'<<_no_of_mails<<'\n';
        }
    }
    nom.close();
    temp.close();

    nom.open("number of mails.txt",ios::out);
    temp.open("temp.txt",ios::in);
    nom.clear();
    while(!temp.eof()){
        temp.getline(_id,5,'|');
        temp.getline(_no_of_mails,3);

        nom<<_id<<'|'<<_no_of_mails<<'\n';
    }
    nom.close();
    temp.close();
    remove("temp.txt");
}
void Email::print(string ID)
{
    mail.open("email.txt",ios::in);
    cout<<"\n";
    while(!mail.eof()){
        mail.getline(_id,5,'|');
        mail.getline(_mail,60,'|');
        mail.getline(_type,30);

        string s = _id;
        if(s.size() == 0)
            break;
        if(s == ID){
            cout<<"\n E-mail : "<<_mail<<"\t  The type : "<<_type;
        }
    }
    mail.close();
}
Email::~Email()
{
    //dtor
}
