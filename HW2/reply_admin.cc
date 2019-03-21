//댓글 관리 프로그램 reply_admin.cc
 
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

const int NUM_OF_CHAT = 200;

int getChatCount(string *_chatList){
    
    int i;
    
    for(i=0;i<NUM_OF_CHAT;++i){
        string s = _chatList[i];
        if(s.empty() == true) break;
    }
    
    return i;
}

void printChat(string* _chatList){
    
    int count = getChatCount(_chatList);
    
    for(int i=0;i<count;++i){
        cout << i << " " << _chatList[i] << endl;
    }
}

bool addChat(string* _chatList, string _chat){
    
    int count = getChatCount(_chatList);
    _chatList[count]=_chat;
    
    return true;
}
bool removeChat(string *_chatList, int _index){
    
    int count = getChatCount(_chatList);
    
    if(_index+1>count) return false;
    
    int i;
    for(i=_index;i<count-1;i++){
        _chatList[i]=_chatList[i+1];
    }
    _chatList[i]="";
    
    return true;
}

int toInt(string number){
    
    int result=0;
    unsigned long len = number.length();
    
    reverse(number.begin(),number.end());
    
    for(int i=0;i<len;i++){
        if(number[i]=='0') result += 0*pow(10,i);
        if(number[i]=='1') result += 1*pow(10,i);
        if(number[i]=='2') result += 2*pow(10,i);
        if(number[i]=='3') result += 3*pow(10,i);
        if(number[i]=='4') result += 4*pow(10,i);
        if(number[i]=='5') result += 5*pow(10,i);
        if(number[i]=='6') result += 6*pow(10,i);
        if(number[i]=='7') result += 7*pow(10,i);
        if(number[i]=='8') result += 8*pow(10,i);
        if(number[i]=='9') result += 9*pow(10,i);
    }
    
    return result;
}

int main(void){
    
    string* chats = new string[NUM_OF_CHAT];
    
    addChat(chats,"Hello, Reply Administrator!");
    addChat(chats,"I will be a good programmer.");
    addChat(chats,"This class is awesome.");
    addChat(chats,"Professor Lim is wise.");
    addChat(chats,"Two TAs are kind and helpful.");
    addChat(chats,"I think TAs look cool");
    
    while(true){
        
        string command;
        getline(cin,command);
    
        if(command.compare("#quit")==0) break;
        
        else if(command.substr(0,7)=="#remove"){
            int arr[201];
            for(int i=0;i<201;i++) arr[i]=0;
            int index=0,i=0;
            if(command.find(",")!=string::npos){
                command = command.substr(8);
                while(command.find(",")!=string::npos){
                    unsigned long posit = command.find(",");
                    string save = command.substr(0,posit);
                    arr[i]=toInt(save);
                    command.erase(0,posit+1);
                    i++;
                }
                arr[i]=toInt(command);
                sort(arr,arr+i+1);
                for(int j=i;j>=0;j--) removeChat(chats,arr[j]);
            }
            else if(command.find("-")!=string::npos){
                unsigned long posit = command.find("-");
                string save1 = command.substr(8,posit-8);
                string save2 = command.substr(posit+1,command.length()-posit);
                if(save1>save2) continue;
                for(int i=toInt(save2);i>=toInt(save1);i--){
                    removeChat(chats,i);
                }
            }
            else{
                string save = command.substr(8);
                index = toInt(save);
                int count = getChatCount(chats);
                if(index>=count) continue;
                else removeChat(chats,index);
            }
            printChat(chats);
        }
        
        else if(addChat(chats,command)){
            printChat(chats);
        }
    }
    
    delete[] chats;
    
    return 0;
}
