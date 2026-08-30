/*
 * PQCMessageWrapper_mlkem_mldsa.h
 *
 *  Created on: 18 apr. 2026
 *      Author: Tomas Jonsson
 */

#ifndef __VEINSPQCSIM_PQCMESSAGEWRAPPER_MLKEM_MLDSA_H
#define __VEINSPQCSIM_PQCMESSAGEWRAPPER_MLKEM_MLDSA_H

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

#include "ApplicationLayerMessage_mlkem_mldsa_m.h"

namespace veinspqcsim {

class VEINSPQCSIM_API PQCMessageWrapper_mlkem_mldsa : public ApplicationLayerMessage_mlkem_mldsa{
    public:
        PQCMessageWrapper_mlkem_mldsa(const char *name = nullptr, short kind = 0);
        PQCMessageWrapper_mlkem_mldsa(const PQCMessageWrapper_mlkem_mldsa& other);
        virtual PQCMessageWrapper_mlkem_mldsa *dup() const override;

        void setSignatureBulk(const uint8_t* data, size_t len);

        uint8_t* getSignatureBuffer();
        const uint8_t* getSignatureBuffer() const;

        void setPubKeyBulk(const uint8_t* data, size_t len);
        uint8_t* getPubKeyBuffer();
        const uint8_t* getPubKeyBuffer() const;

        void setKemCipherBulk(const uint8_t* data, size_t len);
        uint8_t* getKemCipherBuffer();
        const uint8_t* getKemCipherBuffer() const;

        void setKemPublicKeyBulk(const uint8_t* data, size_t len);
        uint8_t* getKemPublicKeyBuffer();
        const uint8_t* getKemPublicKeyBuffer() const;
};


}  // namespace veinspqcsim

#endif /* VEINSPQCSIM_PQCMESSAGEWRAPPER_MLKEM_MLDSA_H_ */
