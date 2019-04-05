#include "pkcs5.h"
#include "stdlib.h"
#include "string.h"

uint8_t* PKCS5Padding(uint8_t* data, uint32_t length,uint32_t* padded_len)
{

  uint8_t mod = length %  16;
  uint8_t padding = BLOCK_SIZE - mod;
  *padded_len = length + padding;

  uint8_t* result = malloc(*padded_len*sizeof(uint8_t));

  memcpy(result,data,length);

  for(int i=length;i<length+padding;i++){
    result[i] = padding;
  }

  return result;
}

void InvPKCS5Padding(uint8_t* data, uint32_t length,uint32_t* unpadded_len)
{
	uint8_t padding = data[length-1];
	*unpadded_len = length-padding;
}