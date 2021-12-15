//
// Created by Anton Claudia on 12.12.2021.
//

#ifndef HABITICA_REPOHABITS_H
#define HABITICA_REPOHABITS_H

#pragma once
#include<string>
#include <vector>
#include "Habits.h"

using namespace std;

class RepoHabits{
private:
    vector<Habits> habits;
public:
    void add(const Habits& hb){habits.push_back(hb);}
    vector<Habits> getHabits(){return habits;}
};




#endif //HABITICA_REPOHABITS_H
