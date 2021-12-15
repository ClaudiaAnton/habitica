//
// Created by Anton Claudia on 06.12.2021.
//

#ifndef TRIEDIT_USER_H
#define TRIEDIT_USER_H

#pragma once

#include<string>
#include "ToDoList.h"
#include "Habits.h"
#include "Daily.h"

using namespace std;

class User {
private:
    string username;
    int age, score;
    vector<Habits> habits;
//    ToDoList todo;
//    Habits habits;
//    Daily daily;
public:
    User(const string &username, int age) : username(username), age(age) {}

    const string &getUsername() const { return username; }

//    const ToDoList &getTodo() const {return todo;}
//
//    void setTodo(const ToDoList &todo) {User::todo = todo;}
//
//    const Daily &getDaily() const {return daily;}
//
//    const Habits &getHabits() const {return habits;}
//
//    void setHabits(const Habits &habits) {User::habits = habits;}

    void setUsername(const string &username) { User::username = username; }

    int getAge() const {return age;}

    void setAge(int age) {User::age = age;}

    int getScore() const {return score;}

    void setScore(int score) {User::score = score;}

};

#endif //TRIEDIT_USER_H
