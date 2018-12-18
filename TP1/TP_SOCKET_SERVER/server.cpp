#include "server.h"

#include <QtNetwork>
#include <stdlib.h>
#include <iostream>

//###############################################################################################################
// Constructeur
Server::Server()
:   m_tcp_server(0), m_network_session(0)
{
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config = manager.defaultConfiguration();
    m_network_session = new QNetworkSession(config, this);

    // La méthode sessionOuverte sera appelée sur le signal opened
    connect(m_network_session, SIGNAL(opened()), this, SLOT(sessionOuverte()));

    // Ouverture de la session
    m_network_session->open();

    // La méthode connexionClient sera appelée sur le signal newConnection
    connect(m_tcp_server, SIGNAL(newConnection()), this, SLOT(connexionClient()));
}

//###############################################################################################################
// Méthode appelée lors de l'ouverture de session
void Server::sessionOuverte()
{
    m_tcp_server = new QTcpServer(this); // instanciation

    if (!m_tcp_server->listen(QHostAddress::Any, 53000)) // on écoute sur le port 53000
    {
        std::cout << "Le serveur n'a pas été correctement lancee." << std::endl;
    }
    else
    {
        std::cout << "Le serveur est pret \n\nIP: " << m_tcp_server->serverAddress().toString().toStdString()
                  << std::endl << "port: " << m_tcp_server->serverPort() << std::endl
                  <<  "Lancez l'application Client maintenant." << std::endl;
    }
}

//###############################################################################################################
// Méthode appelée lors de l'ouverture d'une connexion avec un client
void Server::connexionClient()
{
    // instanciation
    m_socket_client = m_tcp_server->nextPendingConnection();

    envoiTexte("Bonjour");
}

//###############################################################################################################
// Méthode envoyant un texte au client
void Server::envoiTexte( const std::string& s )
{
    std::cout << "Envoi de : " << s << std::endl;
    QString texte = tr(s.c_str());
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << texte;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    m_socket_client->write(block);
}
