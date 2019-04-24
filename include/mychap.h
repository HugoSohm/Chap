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

#define PCKT_LEN 8192

typedef struct iph_s
{
    struct sockaddr_in sin;
    struct sockaddr_in din;
    unsigned char version;
    unsigned char ihl;
    unsigned char tos;
    unsigned short int len;
    unsigned short int id;
    unsigned short int flags;
    unsigned short int offset;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short int csum;
    uint32_t src;
    uint32_t dest;
} iph_t;

typedef struct iph2_s
{
    struct sockaddr_in sin;
    struct sockaddr_in din;
    unsigned char version;
    unsigned char ihl;
    unsigned char tos;
    unsigned short int len;
    unsigned short int id;
    unsigned short int flags;
    unsigned short int offset;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short int csum;
    uint32_t src;
    uint32_t dest;
} iph2_t;

typedef struct udph_s
{
    unsigned short int udph_srcport;
    unsigned short int udph_destport;
    unsigned short int udph_len;
    unsigned short int udph_chksum;
} udph_t;

typedef struct tcph_s
{
    unsigned short int srcport;
    unsigned short int destport;
    unsigned int seqnum;
    unsigned int acknum;
    unsigned char reserved : 4, offset : 4;
    unsigned int
        tcp_res1 : 4,
        hlen : 4,
        fin : 1,
        syn : 1,
        rst : 1,
        psh : 1,
        ack : 1,
        urg : 1,
        res2 : 2;
    unsigned short int win;
    unsigned short int chksum;
    unsigned short int urgptr;
} tcph_t;

int main(int ac, char **av);
int mychap(int ac, char **av);
int mychap2(int ac, char **av);
void help();

unsigned short csum(unsigned short *buf, int nwords);
unsigned short csum2(unsigned short *buf, int len);
void sending(int sd, char *buffer, iph_t *iph);
void sending2(int sd, char *buffer, iph2_t *iph2);

iph_t *init_iph(int ac, char **av);
iph2_t *init_iph2(int ac, char **av);
udph_t *init_udph(int ac, char **av);
tcph_t *init_tcph(int ac, char **av);

#endif