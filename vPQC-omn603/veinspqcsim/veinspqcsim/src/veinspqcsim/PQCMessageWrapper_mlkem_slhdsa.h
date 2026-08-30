/*
 * PQCMessageWrapper_mlkem_slhdsa.h
 *
 *  Created on: 8 juni 2026
 *      Author: Tomas Jonsson
 */

#ifndef VEINSPQCSIM_PQCMESSAGEWRAPPER_MLKEM_SLHDSA_H_
#define VEINSPQCSIM_PQCMESSAGEWRAPPER_MLKEM_SLHDSA_H_

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

#include "ApplicationLayerMessage_mlkem_slhdsa_m.h"

namespace veinspqcsim {

class VEINSPQCSIM_API PQCMessageWrapper_mlkem_slhdsa : public ApplicationLayerMessage_mlkem_slhdsa{
    public:
        PQCMessageWrapper_mlkem_slhdsa(const char *name = nullptr, short kind = 0);
        PQCMessageWrapper_mlkem_slhdsa(const PQCMessageWrapper_mlkem_slhdsa& other);
        virtual PQCMessageWrapper_mlkem_slhdsa *dup() const override;

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
#endif /* VEINSPQCSIM_PQCMESSAGEWRAPPER_MLKEM_SLHDSA_H_ */
