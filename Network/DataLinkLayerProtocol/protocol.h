/************************************************************************
 > File Name: protocol.c
 > Author: Tong Cheng
 > Mail: tong.cheng.8819@outlook.com 
 > Created Time: Thu 07 Nov 2019 02:32:44 PM CST
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PKT 1024  // define maximium of packet size

typedef enum{true, false} boolean;
typedef unsigned int seq_nr;
typedef struct{ unsigned char data[MAX_PKT] } packet;
typedef enum{data, ack, nak} frame_kind;
typedef struct{
	frame_kind kind;
	seq_nr seq;
	seq_nr ack;
	packet info;
} frame;

void wait_for_event(event_type *event);
void from_network_layer(packet *p);
void to_network_layer(packet *p);
void from_physical_layer(frame *r);
void to_physical_layer(frame *s);

void start_timer(seq_nr k);
void stop_timer(seq_nr k);
void start_ack_timer(void);
void stop_ack_timer(void);
void enable_network_layer(void);
void disable_network_layer(void);

#define inc(k) if (k < MAX_SEQ) k=k+1; else k=0

