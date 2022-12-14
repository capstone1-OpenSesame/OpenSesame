#ifndef __TCP_H__
#define __TCP_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>

#include "./../tee/doorlock_REE.h"

#define SERV_TCP_PORT	8080
#define SERV_HOST_ADDR	"127.0.0.1"

#define MSG_OK		1
#define MSG_FAIL	0

// 플래그 1: 공개키
// 플래그 2: 암호문
// 플래그 3: 파일

#define SEND_PUBLICKEY		1
#define SEND_ENCRYPTFILE	2
#define SEND_FILE			3

// 도어락 고유번호
#define DOORLOCK "1234567890"

typedef struct {
	int		type;
	char	data[128];
}	MsgType;

typedef struct {
	char symkey[1024];
	char encrypt[1024];
} Encrypt;

void CloseServer(int signo);

void recvFromUser(char *filename, int fileFlag);

#endif