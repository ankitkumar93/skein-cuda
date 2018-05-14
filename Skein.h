#ifndef __SKEIN_H__
#define __SKEIN_H__

#include "Shared.h"

__device__
void ThreeFish256(uint8_t* key, uint8_t* message, uint8_t* tweak)
{

}

__device__
void UniqueBlockIdentifier(uint8_t* key, uint8_t* message, uint8_t* tweak)
{
    
}

__device__
void Skein256(uint8_t* message, size_t messageSize)
{
    uint8_t* key;
    DeviceMalloc((void*)key, kHashSizeBits);
}

#endif // __SKEIN_H__