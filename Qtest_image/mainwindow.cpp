#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // plein écran
    ui->centralWidget->setFixedSize(1920,1080);

    std::cout << "width = " << ui->centralWidget->size().width() << std::endl;

    // création du label

    QLabel *label = new QLabel(this);
    label->setFixedSize( ui->centralWidget->size().width(),
                         ui->centralWidget->size().height());
    QPixmap pix("labyrinthe.png");
    pix.scaled( QSize(100,100) );

    label->setAlignment(Qt::AlignCenter);
    label->setPixmap(pix);

    ui->hellou->raise();
    ui->timer->raise();
    ui->centralWidget->raise();
    ui->centralWidget->raise();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficher_message(QString s)
{
    std::cout << "MainWindow::afficher_message"  << std::endl;
    ui->hellou->setText(s);
    ui->timer->setText(s);
}
void MainWindow::Timers(QString t)
{
    std::cout << "MainWindow::Timers"  << std::endl;
    ui->timer->setText(t);
}
