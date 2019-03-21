#include "reply_admin.h"

ReplyAdmin::ReplyAdmin(){
    chats = new string[NUM_OF_CHAT];
    
    addChat("Hello, Reply Administrator!");
    addChat("I will be a good programmer.");
    addChat("This class is awesome.");
    addChat("Professor Lim is wise.");
    addChat("Two TAs are kind and helpful.");
    addChat("I think male TA looks cool.");
}

ReplyAdmin::~ReplyAdmin(){
}

int ReplyAdmin::getChatCount(){
    int i;
    for(i=0;i<NUM_OF_CHAT;i++){
        string str = chats[i];
        if(str.empty()) break;
    }
    return i;
}

bool ReplyAdmin::addChat(string _chat){
    chats[getChatCount()]=_chat;
    return true;
}

bool ReplyAdmin::removeChat(int _index){
    if(_index + 1 > getChatCount()) return false;
    int i;
    for(i=_index;i<getChatCount()-1;i++){
        chats[i]=chats[i+1];
    }
    chats[i]="";
    return true;
}// #remove #

bool ReplyAdmin::removeChat(int *_indices, int _count){
    sort(_indices,_indices+_count);
    for(int i=_count-1;i>=0;i--){
        if(_indices[i]>=0 && _indices[i]<getChatCount()){
            removeChat(_indices[i]);
        }
    }
    return true;
}// #remove #,#,#,#

bool ReplyAdmin::removeChat(int _start, int _end){
    if(_start<0) _start = 0;
    if(_end+1 >getChatCount()) _end = getChatCount()-1;
    for(int i=_end;i>=_start;i--){
        removeChat(i);
    }
    return true;
}// #remove #-#

void ReplyAdmin::printChat(){
    for(int i=0;i<getChatCount();i++){
        cout << i << " " << chats[i] << endl;
    }
}
