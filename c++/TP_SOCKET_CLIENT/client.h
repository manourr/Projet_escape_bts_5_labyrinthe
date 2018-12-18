
#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>

class QTcpSocket;
class QNetworkSession;

class Client : public QObject
{
    Q_OBJECT

public:
    Client();

private slots:
    void lireTexte();
    void afficherErreur(QAbstractSocket::SocketError socketError);
    void envoiTexte( const std::string& s );

private:
    QTcpSocket *m_tcpSocket;
    quint16 m_blockSize;
    QNetworkSession *m_networkSession;
};

#endif
