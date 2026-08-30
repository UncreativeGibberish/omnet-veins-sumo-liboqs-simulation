/*
 * PQCRSUMessageWrapper_mlkem_slhdsa.h
 *
 *  Created on: 9 juni 2026
 *      Author: Administrator
 */
#pragma once
#ifndef VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_MLKEM_SLHDSA_H_
#define VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_MLKEM_SLHDSA_H_

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

#ifndef VEINSPQCSIM_API
#  if defined(VEINSPQCSIM_EXPORT)
#    define VEINSPQCSIM_API  OPP_DLLEXPORT
#  elif defined(VEINSPQCSIM_IMPORT)
#    define VEINSPQCSIM_API  OPP_DLLIMPORT
#  else
#    define VEINSPQCSIM_API
#  endif
#endif

#include "RSUKemPubKeyAnnouncement_mlkem_slhdsa_m.h"

namespace veinspqcsim {

class VEINSPQCSIM_API PQCRSUMessageWrapper_mlkem_slhdsa : public RSUKemPubKeyAnnouncement_mlkem_slhdsa{
    public:
        PQCRSUMessageWrapper_mlkem_slhdsa(const char *name = nullptr, short kind = 0);
        PQCRSUMessageWrapper_mlkem_slhdsa(const PQCRSUMessageWrapper_mlkem_slhdsa& other);
        virtual PQCRSUMessageWrapper_mlkem_slhdsa *dup() const override;

        void setSignatureBulk(const uint8_t* data, size_t len);

        uint8_t* getSignatureBuffer();
        const uint8_t* getSignatureBuffer() const;

        void setPubKeyBulk(const uint8_t* data, size_t len);
        uint8_t* getPubKeyBuffer();
        const uint8_t* getPubKeyBuffer() const;


        void setKemPublicKeyBulk(const uint8_t* data, size_t len);
        uint8_t* getKemPublicKeyBuffer();
        const uint8_t* getKemPublicKeyBuffer() const;

};


}  // namespace veinspqcsim



#endif /* VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_MLKEM_SLHDSA_H_ */
