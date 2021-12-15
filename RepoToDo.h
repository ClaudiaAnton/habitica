//
// Created by Anton Claudia on 14.12.2021.
//

#ifndef HABITICA_REPOTODO_H
#define HABITICA_REPOTODO_H

#pragma once
#include<string>
#include <vector>
#include <iostream>
#include "ToDoList.h"

class RepoToDo
{
private:
    vector<ToDoList> todo;
public:
    void addToDo(const string& usr,const string& st);
    vector<ToDoList> getall(){return todo;}
};

void RepoToDo::addToDo(const string& usr,const string& st) {
    int ok=0;
    for(ToDoList &i:getall()) {
        if (i.getUsername() == usr) {
            i.addActivity(st);
            ok = 1;
        }
    }
    if(ok==0) {
        ToDoList to{usr};
        to.addActivity(st);
        todo.push_back(to);
    }
}


#endif //HABITICA_REPOTODO_H
