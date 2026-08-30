/*
 * PQCRSUMessageWrapper_hqc_mldsa.h
 *
 *  Created on: 10 juni 2026
 *      Author: Administrator
 */

#ifndef VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_HQC_MLDSA_H_
#define VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_HQC_MLDSA_H_


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

#include "RSUKemPubKeyAnnouncement_hqc_mldsa_m.h"

namespace veinspqcsim {

class VEINSPQCSIM_API PQCRSUMessageWrapper_hqc_mldsa : public RSUKemPubKeyAnnouncement_hqc_mldsa{
    public:
        PQCRSUMessageWrapper_hqc_mldsa(const char *name = nullptr, short kind = 0);
        PQCRSUMessageWrapper_hqc_mldsa(const PQCRSUMessageWrapper_hqc_mldsa& other);
        virtual PQCRSUMessageWrapper_hqc_mldsa *dup() const override;

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

#endif /* VEINSPQCSIM_PQCRSUMESSAGEWRAPPER_HQC_MLDSA_H_ */
