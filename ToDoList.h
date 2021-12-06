//
// Created by Anton Claudia on 06.12.2021.
//

#ifndef TRIEDIT_TODOLIST_H
#define TRIEDIT_TODOLIST_H

#pragma once
#include<string>
using namespace std;
#define NUM 100

class ToDoList
{
private:
    string activities[NUM];
public:
    const string *getActivities() const {
        return activities;
    }
};

#endif //TRIEDIT_TODOLIST_H
