/*
 * PQCRSUMessageWrapper_hqc_slhdsa.h
 *
 *  Created on: 19 apr. 2026
 *      Author: Administrator
 */

#ifndef __VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_HQC_SLHDSA_H
#define __VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_HQC_SLHDSA_H

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

#include "RSUKemPubKeyAnnouncement_hqc_slhdsa_m.h"

namespace veinspqcsim {

class VEINSPQCSIM_API PQCRSUMessageWrapper_hqc_slhdsa : public RSUKemPubKeyAnnouncement_hqc_slhdsa{
    public:
        PQCRSUMessageWrapper_hqc_slhdsa(const char *name = nullptr, short kind = 0);
        PQCRSUMessageWrapper_hqc_slhdsa(const PQCRSUMessageWrapper_hqc_slhdsa& other);
        virtual PQCRSUMessageWrapper_hqc_slhdsa *dup() const override;

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


#endif

