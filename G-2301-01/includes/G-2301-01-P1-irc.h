#ifndef _MYIRC_H
#define _MYIRC_H

int nick(char* command, void* more);
int user(char* command, void* more);
int ping(char* command, void* more);
int pong(char* command, void* more);
int no_command(char* command, void* more);

#endif 