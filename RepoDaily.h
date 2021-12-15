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
    void addDoneTask(const string &usr,const string& st);
    void addAllDuties(const string& usr,const string& st);
    vector<Daily> getall(){return daily;}
};

//void RepoDaily::addAllDuties(const string &usr, const string &st) {
//    daily.push_back(Daily{usr,st});
//}

//void RepoDaily::addDoneTask(const string &usr, const string &st) {
//    int ok=1;
//    for(Daily  &i:getall()){
//        if(i.getUsername()==usr){
//            i.addDone(st);ok=0;
//        }
//    }
//    if(ok==1) {
//        Daily d{usr};
//        d.addDone(st);
//        daily.push_back(d);
//    }
//}
//
void RepoDaily::addAllDuties(const string &usr, const string &st) {
    int ok=1;
    for(Daily  &i:getall()){
        if(i.getUsername()==usr){
            //cout<<"am intrat aici";
            i.addAllDuties(st);ok=0;
        }
    }
    if(ok==1) {
        Daily d{usr};
        d.addAllDuties(st);
        daily.push_back(d);
    }
}

#endif //HABITICA_REPODAILY_H
