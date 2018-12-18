#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class QTcpServer;
class QTcpSocket;
class QNetworkSession;

class Server : public QObject{
    Q_OBJECT

public:
    Server();

private slots:
    void sessionOuverte();
    void connexionClient();

private:
    void envoiTexte( const std::string& s);

private:
    QTcpServer *m_tcp_server; // La socket général
    QTcpSocket *m_socket_client; // La socket client
    QNetworkSession *m_network_session; // La session de connexion
};

#endif
