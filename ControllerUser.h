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
    vector<Habits> getAllHabits(){return repoHabits.getHabits();}
    void addHabits(const string& username, const string &nume, const string &tip, const string &descriere);
    vector<Habits> getAllHabitsOfAUser(const string& st);

    ///DAILY
    void addDailyDuty(const string&usr, const string&st);
    vector<string> getAllDailyDutiesOfAUser(const string&usr);

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

void ControllerUser::addHabits(const string &username, const string &nume, const string &tip, const string &descriere) {
    User usr= findOne(username);
    if(usr.getUsername().compare("null")==0) throw ContrError{"This user doesn't exist!"};
    if(descriere.empty())
        repoHabits.add(Habits{username,nume,tip});
    else
        repoHabits.add(Habits{username,nume,tip,descriere});
}

vector<Habits> ControllerUser::getAllHabitsOfAUser(const string &st) {
    vector<Habits> list;
    for(const auto&i: getAllHabits())
        if(i.getUsername().compare(st)==0)
            list.push_back(i);
    return list;
}

void ControllerUser::addToDo(const string &username, const string &st) {
    User usr= findOne(username);
    if(usr.getUsername().compare("null")==0) throw ContrError{"This user doesn't exist!"};
    repoToDo.addToDo(username,st);
}

vector<string> ControllerUser::getAllToDoOfAUser(const string &username) {
    User usr= findOne(username);
    if(usr.getUsername().compare("null")==0) throw ContrError{"This user doesn't exist!"};
    for(ToDoList &i:repoToDo.getall()) {
        if (i.getUsername() == username) {
            cout<<i.getActivities().size();
            return i.getActivities();
        }
    }
}

void ControllerUser::addDailyDuty(const string &usr, const string &st) {
    repoDaily.addAllDuties(usr,st);
}

vector<string> ControllerUser::getAllDailyDutiesOfAUser(const string &usr) {
    for(Daily  &i:repoDaily.getall())
    {
        if(i.getUsername()==usr){
            for(const auto&j:i.getDuties())
                cout<<j<<endl;
            return i.getDuties();
        }

    }
}


#endif //HABITICA_CONTROLLERUSER_H
