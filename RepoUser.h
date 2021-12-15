//
// Created by Anton Claudia on 12.12.2021.
//

#ifndef HABITICA_REPOUSER_H
#define HABITICA_REPOUSER_H

#pragma once
#include<string>
#include <vector>
#include "User.h"

using namespace std;

class RepoUser
{
private:
    vector<User> users;
public:
        void add(const User &a){users.push_back(a);}
        vector<User> getall(){return users;}
        void addToDo(const User& u,const ToDoList& todo);
//        void addActivity(const string& smth);
};

void RepoUser::addToDo(const User& u,const ToDoList& todo) {
//    for(User &i:users)
//        if(i.getUsername()==u.getUsername())
//            i.setTodo(todo);

}


#endif //HABITICA_REPOUSER_H
