#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void afficher_message( QString s );
    void Timers(QString s);

private:
    Ui::MainWindow *ui;
    QLabel *label;
};

#endif // MAINWINDOW_H
