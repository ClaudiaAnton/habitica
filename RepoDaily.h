//
// Created by Anton Claudia on 14.12.2021.
//

#ifndef HABITICA_REPODAILY_H
#define HABITICA_REPODAILY_H

#pragma once
#include<string>
#include <vector>
#include "Daily.h"

class RepoDaily
{
private:
    vector<Daily> daily;
public:
    vector<Daily>& getall(){return daily;}

    ///Done
    void addDoneTask(const string &usr,const string& st);
    vector<string> getAllDone(const string& st);

    ///All Daily
    void addAllDuties(const string& usr,const string& st);
    vector<string> getAllDailyDuties(const string&usr);


    ///In Progress
    vector<string> getAllInProgress(const string& usr);
};

void RepoDaily::addAllDuties(const string &usr, const string &st) {
    for(Daily  &i:getall()){
        if(i.getUsername()==usr){
            i.addAllDuties(st);
            return;
        }
    }
    Daily d{usr};
    d.addAllDuties(st);
    daily.push_back(d);

}

void RepoDaily::addDoneTask(const string &usr, const string &st) {
    for(Daily  &i:getall()){
        if(i.getUsername()==usr){
            i.addDone(st);
            return;
        }
    }
    Daily d{usr};
    d.addDone(st);
    daily.push_back(d);

}

vector<string> RepoDaily::getAllDailyDuties(const string &usr) {
    for(Daily &i:getall())
        if(i.getUsername()==usr)
            return i.getDuties();
}

vector<string> RepoDaily::getAllDone(const string &st) {
    for(Daily &i:getall())
        if(i.getUsername()==st)
            return i.getAllDone();
}

vector<string> RepoDaily::getAllInProgress(const string &usr) {
    vector<string> list;
    for(Daily&i:getall())
        if(i.getUsername()==usr)
            for(const string& j: i.getDuties())
                if(find(i.getAllDone().begin(),i.getAllDone().end(),j)==i.getAllDone().end())
                    list.push_back(j);
    return list;
}

#endif //HABITICA_REPODAILY_H
