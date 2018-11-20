#include "positioncurseur.h"
#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include "iostream"
#include <QRgb>
#include "windows.h"

using namespace std;

int main(int argc, char *argv[])
{
    QFile File("stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    QApplication a(argc, argv);
    a.setStyleSheet(StyleSheet);

    QPixmap pix = QPixmap("bg.png");

    while(1)
    {
        POINT position_curseur;
        int posa, posb;

        GetCursorPos(&position_curseur);
        posa = position_curseur.y;
        posb = position_curseur.x;
        printf("X : %ld - Y : %ld\n", posa,posb);

        while (qRed( pix.toImage().pixel(posa, posb) ) != 255)
        {
            if(qRed( pix.toImage().pixel(posa,posb) ) == 225)
            {
                cout<<"C est du blanc"<<endl;
            }
            else
            {
                cout<<"C est du noir" <<endl;
            }
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
