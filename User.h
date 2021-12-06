//
// Created by Anton Claudia on 06.12.2021.
//

#ifndef TRIEDIT_USER_H
#define TRIEDIT_USER_H

#pragma once
#include<string>
using namespace std;

class User
{
private:
public:
    const string &getUsername() const {
        return username;
    }

    void setUsername(const string &username) {
        User::username = username;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        User::age = age;
    }

    int getScore() const {
        return score;
    }

    void setScore(int score) {
        User::score = score;
    }

private:
    string username;
    int age,score;
public:

};

#endif //TRIEDIT_USER_H
