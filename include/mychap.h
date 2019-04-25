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

typedef struct udph_s
{
    unsigned short int udph_srcport;
    unsigned short int udph_destport;
    unsigned short int udph_len;
    unsigned short int udph_chksum;
} udph_t;

int main(int ac, char **av);
int mychap(int ac, char **av);
void help(void);

unsigned short csum(unsigned short *buf, int nwords);
void sending(int sd, char *buffer, iph_t *iph);

void init_iph(int ac, char **av, iph_t *iph);
void init_udph(int ac, char **av, udph_t *udph);

#endif