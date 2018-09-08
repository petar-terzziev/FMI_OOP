#include "system.h"
using std::cin;
using std::cout;
SYSTEM::SYSTEM(const char* str,unsigned n):
    admin(str,n)

{}
void SYSTEM::block_user(const char* blocker,const char* user){
 User* u=get_user(user);
 if(!u) throw "no such user";
Moderator* m=get_moderator(blocker);
if(!m) throw "no such moderator";
m->block_user(blocked_users,u);
}

void SYSTEM::unblock_user(const char* blocker,const char* user){
 User* u=get_user(user);
 if(!u) throw "no such user";
Moderator* m=get_moderator(blocker);
if(!m) throw "no such moderator";
m->unblock_user(blocked_users,u);
}

User* SYSTEM::get_user(const char* name){
    if(!strcmp(admin.get_name(),name)) return &admin;
    unsigned s=users.size();
for(int i=0;i<s;i++){
    if(!strcmp(users[i].get_name(),name)) return &users[i];
}
unsigned j=moderators.size();
for(int i=0;i<j;i++){
    if(!strcmp(moderators[i].get_name(),name)) return &moderators[i];
}
return nullptr;
}
Moderator* SYSTEM::get_moderator(const char* name){
    if(!strcmp(admin.get_name(),name)) return &admin;
unsigned j=moderators.size();
for(int i=0;i<j;i++){
    if(!strcmp(moderators[i].get_name(),name)) return &moderators[i];
}
return nullptr;
}
bool SYSTEM::is_blocked(User* user){
 return blocked_users.contains(user);
}
bool SYSTEM::is_blocked(const char* name){
    User* user=get_user(name);
 return blocked_users.contains(user);
}
void SYSTEM::process_command(char* actor,char* action){
if(!strcmp(action,"add_user")){
        if(strcmp(actor,admin.get_name())) throw "You don't have authority";
        char name[50];
        unsigned age;
        cin>>name>>age;
        if(age<16||age>100) throw "Age must be between 16 and 100";
            User u(name,age);
        admin.add_user(users,u);
}

if(!strcmp(action,"add_moderator")){
        if(strcmp(actor,admin.get_name())) throw "You don't have authority";
        char name[50];
        unsigned age;
        cin>>name>>age;
        if(age<16||age>100) throw "Age must be between 16 and 100";
            Moderator m(name,age);
        admin.add_mod(moderators,m);
}


else if(!strcmp(action,"add_post")){
     char type[5];
     cout<<"Enter the type of the post you wish to make(img,url,txt)"<<std::endl;
     cin>>type;
     if(!strcmp(type,"img")){
        char path[50];
        cin>>path;
        Image_Post to_post(path);
        add_post(actor,to_post);
     }
       else  if(!strcmp(type,"url")){
        char path[50];
        cin>>path;
        char description[50];
        cin.ignore();
        cin.getline(description,49);
        URL_Post to_post(path,description);
            add_post(actor,to_post);
     }
    else if(!strcmp(type,"txt")){
        char* text=new char [200];
        cin.ignore();
       cin.getline(text,199,'\n');
       Text_Post to_post(text);
       delete [] text;
           add_post(actor,to_post);
       }
     else{
        std::cout<<"No such type of post"<<std::endl;
     }

}
else if(!strcmp(action,"remove_post")){
    User* u=get_user(actor);
    if(!u) throw "no such user";
    unsigned n;
    cin>>n;
    u->remove_post(n);
}
else if(!strcmp(action,"view_post")){

        int post_n;
    cin>>post_n;
generate_post(post_n);
}
else if(!strcmp(action,"block_user")){
    char name[50];
    cin>>name;
    block_user(actor,name);
}
else if(!strcmp(action,"unblock_user")){
    char name[50];
    cin>>name;
    unblock_user(actor,name);
}

}

void SYSTEM::add_post (const char* name,Post& post){
    User* user=get_user(name);
    if(!user) throw "no such user";
    if(!is_blocked(user)) user->add_post(post);
}
void SYSTEM::generate_post(unsigned n){
    Post* p=admin.get_post(n);
      if(p){
        char* html=p->Make_HTML();
        char* file_path=file_name(n);
        std::ofstream file(file_path);
        file<<html<<std::endl;
        delete [] html;
        delete [] file_path;
        return;
        }
         unsigned j=moderators.size();
    for(int i=0;i<j;i++){
            p= moderators[i].get_post(n);
    if(p){
        char* html=p->Make_HTML();
        char* file_path=file_name(n);
        std::ofstream file(file_path);
        file<<html<<std::endl;
        delete [] html;
        delete [] file_path;
        return;
        }
    }
    unsigned s=users.size();
    for(int i=0;i<s;i++){
            p= users[i].get_post(n);
    if(p){
        char* html=p->Make_HTML();
        char* file_path=file_name(n);
        std::ofstream file(file_path);
        file<<html<<std::endl;
        delete [] html;
        delete [] file_path;
        return;
        }

    }
}
char* SYSTEM::file_name(unsigned n){
    char* numbers=inttc(n);
char* fp=new char [strlen(numbers)+10];
strcpy(fp,"Post#");
strcat(fp,numbers);
strcat(fp,".html");
delete [] numbers;
return fp;
}
SYSTEM::~SYSTEM()
{}
