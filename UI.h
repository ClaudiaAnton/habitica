//
// Created by Anton Claudia on 12.12.2021.
//

#ifndef HABITICA_UI_H
#define HABITICA_UI_H
#pragma once
#include<string>
#include <iostream>
#include "ControllerUser.h"
#include "RepoHabits.h"

using namespace std;

class UI
{
private:
    ControllerUser &controllerUser;
    RepoHabits &habitsContr;
    ToDoList &toDoList;
    Daily &daily;
public:
    UI(ControllerUser &controllerUser, RepoHabits &habitsContr, Daily &dailyl, ToDoList &toDoList)
            : controllerUser(controllerUser), habitsContr(habitsContr), daily(dailyl), toDoList(toDoList) {};
    void menu();
    void start();
    void loginMenu();
    void userMenu(string usr);
};

void UI::menu() {
    cout<<"1.Login"<<endl;
    cout<<"2.Create new user"<<endl;
    cout<<"3.Show all users"<<endl;
    cout<<"0.Exit"<<endl;
}

void UI::start() {
    while (1)
    {
        menu();
        int x;
        cin>>x;
        switch (x) {
            case 1:
            {
                cout<<"Username: ";
                string urs;
                User usr=controllerUser.findOne(urs);
                if(usr.getUsername()=="null"){
                    cout<<"Nu exista acest User"<<endl;
                    break;
                }
                userMenu(urs);
                break;
            }
            case 2:{
                string username;
                int age;
                cout<<"Username: ";
                cin>>username;
                cout<<"Age: ";
                cin>>age;
                try{
                    //controllerUser.adauga(username,age);
                }catch (ContrError& err){
                    err.get_error();
                }
                break;
            }
            case 3:
            {
                for(const auto&i:controllerUser.getAll())
                    cout<<i.getUsername()<<" "<<i.getAge()<<endl;
                break;
            }
            case 0:return;
        }
    }
}

void UI::loginMenu() {
    cout<<"1.Add new Habit"<<endl;
    cout<<"2.Add new task on the ToDoList"<<endl;
    cout<<"3.Add new activity in your daily routine"<<endl;
    cout<<"4.Mark as finished"<<endl;
    cout<<"5.Show all Habits"<<endl;
    cout<<"6.Show the ToDoList"<<endl;
    cout<<"7.Show all finished Daily tasks"<<endl;
    cout<<"8.Show in progress Daily tasks"<<endl;
    cout<<"0.Exit"<<endl;
}

void UI::userMenu(string usr) {
    while (1)
    {
        loginMenu();
        int x;
        switch (x) {
            case 1:
            {
                cout<<"New habit: ";
                string name,tip,descriere;
                cin>>name;
                cout<<"Tip bun/rau: ";
                cin>>tip;
                cout<<"Descriere(it can be null, just press enter): ";
                cin>>descriere;
                //habitsContr.addHabit(name,tip,descriere);
                break;
            }
            case 2:
            {
                cout<<"New task on the ToDoList:";
                string ac;
                cin>>ac;
                toDoList.addActivity(ac);
                break;
            }
            case 3:
            {
                cout<<"New daily activity:";
                string ac;
                cin>>ac;
                //daily.addAllDuties(ac);
                break;
            }
            case 4:
            {
                for(const auto& i:daily.getDuties())
                    cout<<i<<endl;
                cout<<"What activity did u just finished?";
                string ac;
                cin>>ac;
                //daily.addDone(ac);
                break;
            }
            case 5:
            {
                for(const auto& i:habitsContr.getHabits())
                    cout<<i.getNume()<<" "<<i.getTip()<<" "<<i.getDescriere()<<endl;
                break;
            }
            case 6:
            {
                for(const auto &i:toDoList.getActivities())
                    cout<<i<<endl;
                break;
            }
            case 7:
            {
                for(const auto &i: daily.getAllDone())
                    cout<<i;
                break;
            }
            case 8:
            {
                for(const auto&i:daily.getInProgress())
                    cout<<i<<endl;
                break;
            }
            case 0:return;
        }
    }
}


#endif //HABITICA_UI_H
