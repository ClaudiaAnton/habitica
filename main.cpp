// 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

//https://stackoverflow.com/questions/47769781/edit-ui-files-with-clion

//https://www.youtube.com/watch?v=Sp5TywYeNzE

#include <QApplication>
#include <QPushButton>
//#pragma once
#include<string>
#include "RepoUser.h"
#include "ControllerUser.h"
#include "UI.h"

using namespace std;

int main(int argc, char *argv[]) {
    RepoUser repoUser;
    RepoHabits repoHabits;
    RepoToDo repoToDo;
    RepoDaily repoDaily;
    ControllerUser controllerUser{repoUser,repoToDo,repoHabits,repoDaily};

    //ToDoList toDoList;
    //Daily daily;

    controllerUser.addUser("ana",12);
    controllerUser.addUser("dan",18);
    controllerUser.addUser("pop",19);
    controllerUser.addUser("roxi",22);
    controllerUser.addUser("ion",15);
    ///habits
    controllerUser.addHabits("ana","n1","pozitiv","");
    controllerUser.addHabits("ana","n2","negativ","");
    controllerUser.addHabits("ana","n3","pozitiv","");
    controllerUser.addHabits("ion","n3","pozitiv","");
    for(const auto&i:controllerUser.getAllHabitsOfAUser("ion"))
        cout<<i.getNume()<<" ";

    ///
    controllerUser.addDailyDuty("ana","idkidk");
    controllerUser.addDailyDuty("ana","de facut");
    controllerUser.addDailyDuty("ion","de mancat");



    return 0;
//    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();
}
