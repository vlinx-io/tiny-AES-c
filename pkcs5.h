#ifndef _PKCS5_H_
#define _PKCS5_H_

#include "stdlib.h"

#define BLOCK_SIZE 16

uint8_t* PKCS5Padding(uint8_t* data, uint32_t length,uint32_t* padded_len);
uint8_t* InvPKCS5Padding(uint8_t* data, uint32_t length,uint32_t* unpadded_len);

#endif