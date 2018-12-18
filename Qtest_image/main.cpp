
#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include "iostream"
#include <QLabel>

#include <QCoreApplication>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <QThread>
#include "monthread.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //w.show();
    w.showFullScreen();

    monThread t;
    t.set_app( &w );
    t.start();

    return a.exec();
}
