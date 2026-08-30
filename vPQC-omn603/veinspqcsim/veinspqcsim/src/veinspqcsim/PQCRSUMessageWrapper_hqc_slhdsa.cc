/*
 * PQCRSUMessageWrapper_hqc_slhdsa.cc
 *
 *  Created on: 19 apr. 2026
 *      Author: Administrator
 */
#include "PQCRSUMessageWrapper_hqc_slhdsa.h"
namespace veinspqcsim{
Register_Class(PQCRSUMessageWrapper_hqc_slhdsa)

PQCRSUMessageWrapper_hqc_slhdsa::PQCRSUMessageWrapper_hqc_slhdsa(const char *name, short kind)
        : RSUKemPubKeyAnnouncement_hqc_slhdsa(name, kind){
        // Initialize empty arrays
        std::memset(signature, 0, sizeof(signature));
        std::memset(pubKey, 0, sizeof(pubKey));
        //std::memset(kemCiphertext, 0, sizeof(kemCiphertext));
        std::memset(kemPublicKey, 0, sizeof(kemPublicKey));
        //printf("PQCMessageWrapper_hqc_slhdsa constructed with empty arrays\n");
        //fflush(stdout);
}


PQCRSUMessageWrapper_hqc_slhdsa::PQCRSUMessageWrapper_hqc_slhdsa(const PQCRSUMessageWrapper_hqc_slhdsa& other)
        : RSUKemPubKeyAnnouncement_hqc_slhdsa(other){
    //printf("PQCMessageWrapper_hqc_slhdsa copy constructor called\n");
    //fflush(stdout);
}

PQCRSUMessageWrapper_hqc_slhdsa* PQCRSUMessageWrapper_hqc_slhdsa::dup() const
{
    return new PQCRSUMessageWrapper_hqc_slhdsa(*this);
}

void PQCRSUMessageWrapper_hqc_slhdsa::setSignatureBulk(const uint8_t* data, size_t len)
{
    printf("Entered setSignatureBulk (RSU) with len=%zu\n", len);
    fflush(stdout);

    if (!data || len == 0 || len > sizeof(signature)) {
        printf("setSignatureBulk: Invalid length %zu for array size %zu or no data \n", len, getSignatureArraySize());
        fflush(stdout);
        return;
    }

    // zero the buffer first
    std::memset(signature, 0, len);

    std::memcpy(signature, data, len);

    printf("setSignatureBulk: memcpy of %zu bytes completed successfully\n", len);
    fflush(stdout);

    /*
    printf("First 10 bytes of signature after memcpy: ");
    for (size_t i = 0; i < 10 && i < len; ++i) {
        printf("%02x ", signature[i]);
    }
    printf("\n");
    fflush(stdout);*/
}

uint8_t* PQCRSUMessageWrapper_hqc_slhdsa::getSignatureBuffer(){
    return signature;
}

const uint8_t* PQCRSUMessageWrapper_hqc_slhdsa::getSignatureBuffer() const{
    return signature;
}

void PQCRSUMessageWrapper_hqc_slhdsa::setPubKeyBulk(const uint8_t* data, size_t len){
    if (!data || len == 0 || len > sizeof(signature)) {
        printf("setPubKeyBulk: Invalid length %zu for array size %zu or no data \n", len, getPubKeyArraySize());
        fflush(stdout);
        return;
    }


    std::memset(pubKey, 0, len);
    std::memcpy(pubKey, data, len);

    printf("setpubKeyBulk: memcpy of %zu bytes completed successfully\n", len);
    fflush(stdout);

    // Verify first 10 bytes after copy
    /*printf("First 10 bytes of pubKey after memcpy: ");
    for (size_t i = 0; i < 10 && i < len; ++i) {
        printf("%02x ", pubKey[i]);
    }*/
}

uint8_t* PQCRSUMessageWrapper_hqc_slhdsa::getPubKeyBuffer(){
    return pubKey;
}

const uint8_t* PQCRSUMessageWrapper_hqc_slhdsa::getPubKeyBuffer() const{
    return pubKey;
}


void PQCRSUMessageWrapper_hqc_slhdsa::setKemPublicKeyBulk(const uint8_t* data, size_t len){

    if ( !data ){
        printf( "Data passed to setKemPubKliceyBulk is trash. Do something about that. Returning" );
        return;
    }
    if ( len < 0 ){
        printf( "Invalid size_t len 0" );
        return;
    }
    if (len > getKemPublicKeyArraySize() ){
        printf( "Invalid length %zu for array size %zu", len, getKemPublicKeyArraySize() );
    }


    std::memset( kemPublicKey, 0, len );
    std::memcpy( kemPublicKey, data, len );

    printf( "setKemPublicKeyBulk: memcpy of %zu bytes completed successfully\n", len );
    fflush(stdout);


}

uint8_t* PQCRSUMessageWrapper_hqc_slhdsa::getKemPublicKeyBuffer(){
    return kemPublicKey;
}

const uint8_t* PQCRSUMessageWrapper_hqc_slhdsa::getKemPublicKeyBuffer() const{
    return kemPublicKey;
}

} //namespace veinspqcsim

