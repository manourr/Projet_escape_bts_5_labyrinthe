#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication MyApp(argc,argv);

        QPushButton button("Je suis un bouton");

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
