/* vim: set ts=4 sw=4 et: */
#ifndef _TCPSOCKET_H
#define _TCPSOCKET_H

#include <stdio.h>          
#include <stdlib.h>
#include <pthread.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* Estructuras de datos */
typedef struct {
    int socketd, acceptd; 
    socklen_t clientlen; 
    struct sockaddr_in client;
} tcpsocket_args ;

/* Valores de retorno */
#define TCPCLOSED 1
#define TCPOK 0
#define TCPERR_ARGS -1
#define TCPERR_SOCKET -2
#define TCPERR_BIND -3
#define TCPERR_LISTEN -4
#define TCPERR_ACCEPT -6
#define TCPERR_SEND -7
#define TCPERR_RECV -8

/* Constantes de relevancia */
#define BACKLOG 5

/* Funciones */
int server_tcpsocket_open(uint16_t port, int* socketd);
int client_tcpsocket_open(uint16_t port, int* socketd);
int tcpsocket_accept(int socketd, tcpsocket_args* args);
int tcpsocket_snd(int socketd, void* data, size_t len);
int tcpsocket_rcv(int socketd, void* data, size_t max, size_t* len);

#endif