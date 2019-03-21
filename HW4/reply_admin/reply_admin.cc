#include "reply_admin.h"

using namespace std;

ReplyAdmin::ReplyAdmin(){
    
    list<string> chats;
    
    addChat("Hello, Reply Administrator!");
    addChat("I will be a good programmer.");
    addChat("This class is awesome.");
    addChat("Professor Lim is wise.");
    addChat("Two TAs are kind and helpful.");
    addChat("I think male TA looks cool.");
}

ReplyAdmin::~ReplyAdmin(){
    
}

bool ReplyAdmin::addChat(string _chat){
 
    chats.push_back(_chat);
    
    return true;
}

bool ReplyAdmin::removeChat(int _index){
    
    unsigned long num = chats.size();
    if(chats.size() <= _index) return false;
    
    if(_index > num) return false;
    
    list<string>::iterator it = chats.begin();
    
    advance(it,_index);
    
    chats.erase(it);

    return true;
}

bool ReplyAdmin::removeChat(list<int> _indices){

    _indices.sort();
    unsigned long num = _indices.size();
    
    while(num--){
        
        removeChat(_indices.back());
        _indices.pop_back();
    }
    
    return true;
}

bool ReplyAdmin::removeChat(int _start, int _end){

    bool isChange = false;
    
    for(int i=_end;i>=_start;i--){
        isChange += removeChat(i);
    }
    
    return true;
}

void ReplyAdmin::printChat(){
    
    unsigned long num = chats.size();
    
    for(int i=0;i<num;i++){
        
        cout << i << " " << chats.front() << endl;
        chats.push_back(chats.front());
        chats.pop_front();
    }
    
}

