#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int button;
    int a = 250;
    int b = 230;
    ui->setupUi(this);
    QApplication MyApp(&a,&b);



        QPixmap pix(":/new/prefix1/cur.png");
        pix.setMask(QBitmap(":/new/prefix1/curmap.png"));
        button.setCursor(QCursor(pix));
        button.show();
        return MyApp.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
