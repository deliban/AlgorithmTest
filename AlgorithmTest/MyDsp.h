#pragma once
void JudgeEndian(void);
void JudgeEndian1(void);
static void base64_encode(const char *src, int src_len, char *dst);
static void base64_decode(const char *src, int src_len, char *dst);
void MyBase64Test(void);
void Verfy(void);
char * findcommon2(char a[], char b[]);