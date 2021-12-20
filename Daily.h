//
// Created by Anton Claudia on 12.12.2021.
//

#ifndef HABITICA_DAILY_H
#define HABITICA_DAILY_H

#pragma once
#include<string>
#include <vector>

using namespace std;

class Daily
{
private:
    string username;
    vector<string> allDuties;
    vector<string> done;
    vector<string> inProgress;
public:
    Daily(const string &username) : username(username){}

    ///setter-ish(adugare in vectorii)
    void addAllDuties(const string& str){allDuties.push_back(str);}
    void addDone(const string& str){done.push_back(str);}
    void addInProgress(const string& st){inProgress.push_back(st);}

    ///Getters
    const string &getUsername() const{return username;};
    vector<string>& getAllDone() {return done;}
    vector<string>& getInProgress(){return inProgress;}
    vector<string>& getDuties(){return allDuties;}
};




#endif //HABITICA_DAILY_H
