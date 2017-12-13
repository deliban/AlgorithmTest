#pragma once
static void base64_encode(const char *src, int src_len, char *dst);
static void base64_decode(const char *src, int src_len, char *dst);
void MyBase64Test(void);