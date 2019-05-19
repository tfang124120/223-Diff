#ifndef diff_h
#define diff_h

//combined para.c and util.c

#include <stdio.h>

#define BUFLEN 256

typedef struct para para;
struct para {
  char** base;
  int filesize;
  int start;
  int stop;
  char* firstline;   // DEBUG only
  char* secondline;
};

para* para_make(char* base[], int size, int start, int stop);
para* para_first(char* base[], int size);
para* para_next(para* p);
size_t para_filesize(para* p);
size_t para_size(para* p);
char** para_base(para* p);
char* para_info(para* p);
int   para_equal(para* p, para* q);
void para_print(para* p, void (*fp)(const char*));
void para_printfile(char* base[], int count, void (*fp)(const char*));

char* yesorno(int condition);
FILE* openfile(const char* filename, const char* openflags);
void printleft(const char* left);
void printleft1(const char* left);
void printleft2(const char* left);
void printright(const char* right);
void printboth(const char* left_right);
void printboth2(const char* left_right);
void printline(void);

#endif
