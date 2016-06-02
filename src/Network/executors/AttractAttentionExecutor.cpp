#include "Network/executors/AttractAttentionExecutor.h"
#include "Network/Server.h"
#include "Network/Client.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#if defined(__linux) || defined(__linux__) || defined(linux)
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
#pragma GCC diagnostic ignored "-Wsign-conversion"

namespace Network {

void AttractAttentionExecutor::execute_client()
{

	bool attract;
	int id_user;

	*stream >> attract >> id_user;

	Client* client= Client::getInstance();

	if ( attract ) {
		client->setAttention( id_user );
	}
	else {
		client->unSetAttention( id_user );
	}
}

void AttractAttentionExecutor::execute_server()
{

	QTcpSocket* sender = ( QTcpSocket* ) stream->device();
	bool attract;
	*stream >> attract;

	Server* server = Server::getInstance();
	int id = server->getUserId( sender );

	if ( attract ) {
		server->setAttention( id );
	}
	else {
		server->unSetAttention( id );
	}

	QSet<QTcpSocket*> clients = server->getClients();
	foreach ( QTcpSocket* client, clients ) {
		if ( client == sender ) {
			continue;
		}
		server->sendAttractAttention( attract,id,client );
	}

}

}

#pragma GCC diagnostic pop
