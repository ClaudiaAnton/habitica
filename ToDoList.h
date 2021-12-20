//
// Created by Anton Claudia on 06.12.2021.
//

#ifndef TRIEDIT_TODOLIST_H
#define TRIEDIT_TODOLIST_H

#pragma once
#include<string>
#include <vector>
#include <iostream>

using namespace std;

class ToDoList
{
private:
    string username;
    vector<string> activities;

public:
    ToDoList(const string &username) : username(username){}

    ///Setter-ish
    void addActivity(const string& st){activities.push_back(st);}

    ///Getters
    const string &getUsername() const {return username;}
    vector<string>& getActivities() {return activities;}
};

#endif //TRIEDIT_TODOLIST_H
