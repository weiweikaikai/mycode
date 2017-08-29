#include<iostream>
using namespace std;
#include"RC4.h"


static unsigned char encrypt_temp_result[65536];



void RC4_encrypt_msg(unsigned char* msg,int msglen){

     if(msglen == 0)
         return ;
    
    static const char* key = "}E#<*F46XJCLI(BYInIiX:4wq(.YO(~"
                             "hh.W%w/V~awN#Yyqo!ZZes>9a-cK..."
                             "r6KZ7]UH.]4MjK:TqO'_Jb=;,x}9nti"
                             "eahKi/Q6jZ(#A:.PAT.j0iCNbI>lc`;_pTg";
    RC4_KEY rc4_key;
    RC4_set_key(&rc4_key,strlen(key),(unsigned char*)key);

    static const uint32_t loop = 4;
    unsigned char* bufs[2] = {msg, (unsigned char *)encrypt_temp_result};  

    for(uint32_t i=0; i<loop; ++i){ 
        unsigned char* in_buf = bufs[i & 1];
        unsigned char* out_buf = bufs[(i + 1) & 1];
        RC4(&rc4_key,msglen,in_buf,out_buf);
    }
    unsigned char *result = bufs[loop & 1];
    if(result != msg){
       memcpy(msg,result,msglen);
    }

}

void RC4_decrypt_msg(unsigned char* msg,int msglen){
     
    if(msglen == 0)
         return ;

    RC4_encrypt_msg(msg,msglen);
}


int main(){

  unsigned char in[]="hello wecan";
  RC4_encrypt_msg(in,12);
  cout<<encrypt_temp_result<<endl;

  RC4_decrypt_msg(encrypt_temp_result,12);
  cout<<encrypt_temp_result<<endl;
  
 return 0;
}
