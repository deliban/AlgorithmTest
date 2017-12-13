#include"MyDsp.h"
#include <stdio.h>
#include <stdlib.h>
#include< string.h>
char base64_map[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char base64_decode_map[256] = 
{
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 62, 255, 255, 255, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60,61, 255, 255,
	255, 0, 255, 255, 255, 0,1,  2,3,4,5,6,7,8,9,10,11,12,13,14,
	15,16,17,18,19,20,21,22,23,24,25, 255, 255, 255, 255, 255, 255,26,27,28,
	29,30,31,32,33,34,35,36,7,38,39,40,41,42,43,44,45,46,47,48,
	49,50,51, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 
};

unsigned char test[100] = "testsecret&";
unsigned char test1[100] = "testsecret&";
unsigned char encode[100], decode[100];
unsigned char test2[100] = "Y9eWn4nF8QPh3c4zAFkM/k/u7eA=";
void base64_encode(const char *src, int src_len, char *dst)
{
	int i = 0, j = 0;
	for (i; (src_len - i) / 3; i += 3)
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3f];
		dst[j++] = base64_map[((src[i] << 4) | (src[i + 1] >> 4)) & 0x3f];
		dst[j++] = base64_map[((src[i + 1] << 2) | (src[i + 2] >> 6)) & 0x3f];
		dst[j++] = base64_map[src[i + 2] & 0x3f];
	}

	/*不足3的倍数*/
	if (src_len % 3 == 1)
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3f];
		dst[j++] = base64_map[(src[i] << 4) & 0x3f];
		dst[j++] = '=';
		dst[j++] = '=';
	}
	else if (src_len % 3 == 2) 
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3f];
		dst[j++] = base64_map[((src[i] << 4) | (src[i + 1] >> 4)) & 0x3f];
		dst[j++] = base64_map[(src[i + 1] << 2) & 0x3f];
		dst[j++] = '=';
	}
	dst[j] = '\0';
}

//若是不是4的倍数，强制解码 
void base64_decode(const char *src, int src_len, char *dst)
{
	int i = 0, j = 0;
	if (src_len % 4 != 0)
	{
		printf("sound code is not four time\n");
		exit(1);
	}

	for (i; (src_len - i) / 4; i += 4) 
	{
		dst[j++] = base64_decode_map[src[i]] << 2 | \
			base64_decode_map[src[i + 1]] >> 4;
		dst[j++] = base64_decode_map[src[i + 1]] << 4 | \
			base64_decode_map[src[i + 2]] >> 2;
		dst[j++] = base64_decode_map[src[i + 2]] << 6 | \
			base64_decode_map[src[i + 3]];
	}
	dst[j] = '\0';
}

void MyBase64Test(void)
{

	base64_encode((char*)test, strlen((char*)test), (char*)encode);
	printf("%s\n", encode);

	printf("%s\n", test1);
	base64_encode((char*)test1, strlen((char*)test1), (char*)encode);
	printf("%s\n", encode);

	base64_decode((char*)test2, strlen((char*)test2), (char*)decode);
	printf("%s\n", decode);

}
