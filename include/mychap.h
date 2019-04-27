/*
** EPITECH PROJECT, 2018
** NWP_mychap_2018
** File description:
** mychap.h
*/

#ifndef MYCHAP_H
#define MYCHAP_H

#include <netinet/in_systm.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>

#define BUFSIZE 8192

typedef struct client_s {
    struct sockaddr_in sin;
    char buffer[BUFSIZE];
    char *data;
    int sock;
    int port;
    int addr;
    int len;
    int on;
} client_t;

int main(int ac, char **av);
int mychap(char **av);
void help(void);
void error_msg(char *msg);

void send_msg(client_t *client);

unsigned short csum(unsigned short *buf, int nwords);
void sending(client_t *client);

client_t *init_client();
struct iphdr *init_iphdr(char **av, client_t *client);
struct udphdr *init_udphdr(char **av, client_t *client);

#endif