#ifndef __RC4_H__
#define __RC4_H__

#include<openssl/rc4.h> 
#include<string.h>



void RC4_encrypt_msg(unsigned char* msg,int msglen);
void RC4_decrypt_msg(unsigned char* msg,int msglen);




#endif
