//
// Created by Anton Claudia on 12.12.2021.
//

#ifndef HABITICA_CONTROLLERUSER_H
#define HABITICA_CONTROLLERUSER_H

#pragma once
#include<string>
#include "RepoUser.h"
#include "RepoToDo.h"
#include "RepoHabits.h"
#include "RepoDaily.h"

using namespace std;

class ContrError
{
private:
    string err;
public:
    ContrError(const string& s) :err{ s } {};
    string get_error()
    {
        return err;
    }
};

class ControllerUser
{
private:
    RepoUser& repo;
    RepoToDo& repoToDo;
    RepoHabits& repoHabits;
    RepoDaily& repoDaily;
public:
    ControllerUser(RepoUser &repo, RepoToDo &repoToDo, RepoHabits &repoHabits, RepoDaily &repoDaily) : repo(repo), repoToDo(repoToDo), repoHabits(repoHabits), repoDaily(repoDaily) {}

    ///USER
    void addUser(const string& username, int age);
    vector<User> getAll(){return repo.getall();}
    User findOne(const string &username);

    ///HABITS

    ///DAILY
    void addDailyDuty(const string&usr, const string&st);
    void addDoneDuty(const string& usr,const string &st);
    vector<string> getAllDoneOfAUser(const string& st);
    vector<string> getInProgressOfAUser(const string& st);


    ///TODO
    void addToDo(const string& usr, const string&st);
    vector<string> getAllToDoOfAUser(const string& username);
};

void ControllerUser::addUser(const string &username, int age) {
    if(username.empty()) throw ContrError{"Innvalid username"};
    if(age<10) throw ContrError{"Invalid age"};
    for(const auto &i:getAll())
        if(i.getUsername()==username) throw ContrError{"This username already exists"};
    repo.add( User{username,age});
}

User ControllerUser::findOne(const string &username) {
    if(username.empty()) throw ContrError{"Innvalid username"};
    for(const auto &i:getAll())
        if(i.getUsername()==username) return i;
    return User{"null",12};
}


void ControllerUser::addToDo(const string &username, const string &st) {
    User usr= findOne(username);
    if(usr.getUsername().compare("null")==0) throw ContrError{"This user doesn't exist!"};
    repoToDo.addToDo(username,st);
}

vector<string> ControllerUser::getAllToDoOfAUser(const string &username) {
    User usr= findOne(username);
    list<string> list;
    if(usr.getUsername().compare("null")==0) throw ContrError{"This user doesn't exist!"};
    for(ToDoList &i:repoToDo.getall()) {
        if (i.getUsername() == username) {
            return i.getActivities();
        }
    }
}

void ControllerUser::addDailyDuty(const string &usr, const string &st) {
    repoDaily.addAllDuties(usr,st);
}

void ControllerUser::addDoneDuty(const string &usr, const string &st) {
    repoDaily.addDoneTask(usr,st);
}

vector<string> ControllerUser::getInProgressOfAUser(const string &st) {
    ///validare user
    return repoDaily.getAllInProgress(st);
}




#endif //HABITICA_CONTROLLERUSER_H
