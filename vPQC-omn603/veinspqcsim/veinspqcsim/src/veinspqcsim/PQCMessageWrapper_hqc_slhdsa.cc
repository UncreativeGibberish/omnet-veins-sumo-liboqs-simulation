
/*
 * PQCMessageWrapper_hqc_slhdsa.cc
 *
 *  Created on: 2 May. 2026
 *      Author: Administrator
 */
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif


#include "PQCMessageWrapper_hqc_slhdsa.h"

namespace veinspqcsim {

Register_Class(PQCMessageWrapper_hqc_slhdsa)


PQCMessageWrapper_hqc_slhdsa::PQCMessageWrapper_hqc_slhdsa( const char *name, short kind )
        : ApplicationLayerMessage_hqc_slhdsa(name, kind){
        // Initialize empty arrays
        std::memset( signature, 0, sizeof(signature) );
        std::memset( pubKey, 0, sizeof(pubKey) );
        std::memset( kemCiphertext, 0, sizeof(kemCiphertext) );
        printf( "PQCMessageWrapper_hqc_slhdsa constructed with empty arrays\n" );
        fflush(stdout);
}


PQCMessageWrapper_hqc_slhdsa::PQCMessageWrapper_hqc_slhdsa( const PQCMessageWrapper_hqc_slhdsa& other )
        : ApplicationLayerMessage_hqc_slhdsa(other){
    printf("PQCMessageWrapper_hqc_slhdsa copy constructor called\n");
    fflush(stdout);
}

PQCMessageWrapper_hqc_slhdsa* PQCMessageWrapper_hqc_slhdsa::dup() const
{
    return new PQCMessageWrapper_hqc_slhdsa( *this );
}

void PQCMessageWrapper_hqc_slhdsa::setSignatureBulk( const uint8_t* data, size_t len )
{
    printf( "Entered setSignatureBulk (car) with len=%zu\n", len );
    fflush(stdout);

    if ( !data || len == 0 || len > sizeof(signature) ) {
        //setSignatureArraySize(0);
        printf("setSignatureBulk: Invalid length %zu for array size %zu or no data \n");
        fflush(stdout);
        return;
    }

    std::memset( signature, 0, len );

    std::memcpy( signature, data, len );

    printf( "setSignatureBulk: memcpy of %zu bytes completed successfully\n", len );
    fflush(stdout);

    // Verify first 10 bytes after copy
    printf( "First 10 bytes of signature after memcpy: " );
    for ( size_t i = 0; i < 10 && i < len; ++i ) {
        printf("%02x ", signature[i]);
    }
    printf("\n");
    fflush(stdout);
}

uint8_t* PQCMessageWrapper_hqc_slhdsa::getSignatureBuffer(){
    return signature;
}

const uint8_t* PQCMessageWrapper_hqc_slhdsa::getSignatureBuffer() const{
    return signature;
}

void PQCMessageWrapper_hqc_slhdsa::setPubKeyBulk( const uint8_t* data, size_t len ){
    if (!data || len == 0 || len > sizeof(signature)) {
        printf("setPubKeyBulk: Invalid length %zu for array size %zu or no data \n");
        fflush(stdout);
        //setPubKeyArraySize(0);
        return;
    }

    /*setPubKeyArraySize(len);
    if(getPubKeyArraySize() != len){
        printf("setPubKeyArraySize(%zu) failed. Actual pubKey_arraysize is %zu \n", len, pubKey_arraysize);
        return;
    }*/
    //std::memcpy(pubKey, data, len);
    // zero the buffer first
    std::memset( pubKey, 0, len );

    std::memcpy( pubKey, data, len );

    printf( "setPubKeyBulk: memcpy of %zu bytes completed successfully\n", len );
    fflush(stdout);

    // Verify first 10 bytes after copy
    printf( "First 10 bytes of pubKey after memcpy: " );
    for ( size_t i = 0; i < 10 && i < len; ++i ) {
        printf( "%02x ", pubKey[i] );
    }
}

uint8_t* PQCMessageWrapper_hqc_slhdsa::getPubKeyBuffer(){
    return pubKey;
}

const uint8_t* PQCMessageWrapper_hqc_slhdsa::getPubKeyBuffer() const{
    return pubKey;
}

void PQCMessageWrapper_hqc_slhdsa::setKemCipherBulk( const uint8_t* data, size_t len ){
    if ( !data || len == 0 ) {
        //setKemCiphertextArraySize(0);
        return;
    }

    /*setKemCiphertextArraySize(len);
    if(getKemCiphertextArraySize() != len){
        printf("setKemCiphertextArraySize(%zu) failed. Actual kemCiphertext_arraysize is %zu \n", len, kemCiphertext_arraysize);
        return;
    }*/
    std::memcpy( kemCiphertext, data, len );
}

uint8_t* PQCMessageWrapper_hqc_slhdsa::getKemCipherBuffer(){
    return kemCiphertext;
}

const uint8_t* PQCMessageWrapper_hqc_slhdsa::getKemCipherBuffer() const{
    return kemCiphertext;
}

void PQCMessageWrapper_hqc_slhdsa::setKemPublicKeyBulk(const uint8_t* data, size_t len){

    if ( !data ){
        //printf( "Data passed to setKemPubKeyBulk is trash. Do something about that. Returning" );
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

    printf( "setSignatureBulk: memcpy of %zu bytes completed successfully\n", len );
    fflush(stdout);


}

uint8_t* PQCMessageWrapper_hqc_slhdsa::getKemPublicKeyBuffer(){
    return kemPublicKey;
}

const uint8_t* PQCMessageWrapper_hqc_slhdsa::getKemPublicKeyBuffer() const{
    return kemPublicKey;
}

}
