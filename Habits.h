//
// Created by Anton Claudia on 12.12.2021.
//

#ifndef HABITICA_HABITS_H
#define HABITICA_HABITS_H
#pragma once
#include<string>
using namespace std;

//de generat
class Habits
{
private:
    string username,nume,tip,descriere;
public:
    Habits(const string &username, const string &nume, const string &tip) : username(username), nume(nume), tip(tip) {}

    Habits(const string &username, const string &nume, const string &tip, const string &descriere) : username(username),nume(nume),tip(tip),descriere(descriere) {}

    const string &getUsername() const {return username;}
    const string &getNume() const {return nume;}
    const string &getTip() const {return tip;}
    const string &getDescriere() const {return descriere;}
};

#endif //HABITICA_HABITS_H
