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
#include <openssl/sha.h>
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
#define NONCE_LENGTH 10

typedef struct client_s {
    struct sockaddr_in sin;
    char buffer[BUFSIZE];
    char rec[BUFSIZE];
    char *data;
    char *pass;
    char *addr;
    char *sha;
    int sock;
    int port;
    int len;
    int on;
} client_t;

unsigned short csum(unsigned short *buf, int nwords);
char *sha256(client_t *client, const char *str);
int main(int ac, char **av);
void error_msg(char *msg);
int mychap(char **av);
void help(void);

struct udphdr *init_udphdr(client_t *client);
struct iphdr *init_iphdr(client_t *client);
client_t *init_client();

void new_size(client_t *client);
void send_msg(client_t *client);
void send_mdp(client_t *client);
void get_msg(client_t *client);
void get_mdp(client_t *client);

#endif