#ifndef MONTHREAD_H
#define MONTHREAD_H

#include <QThread>

class MainWindow;

class monThread: public QThread
{
    Q_OBJECT

    protected:
        void run();

public:
        void set_app(MainWindow * app);

private:
    MainWindow * m_app;
};

#endif // MONTHREAD_H
