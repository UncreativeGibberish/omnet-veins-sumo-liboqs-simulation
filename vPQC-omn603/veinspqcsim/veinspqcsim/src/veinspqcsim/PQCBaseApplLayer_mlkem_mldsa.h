/*
 * PQCBaseApplLayer_mlkem_mldsa.h
 *
 *  Created on: 13 apr. 2026
 *      Author: Tomas Jonsson
 */

#pragma once

#include "veinspqcsim/veinspqcsim.h"
#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/base/utils/SimpleAddress_m.h"
#include <set>
#include <map>
#include <oqs/oqs.h>

namespace veinspqcsim {
class VEINSPQCSIM_API PQCBaseApplLayer_mlkem_mldsa : public veins::DemoBaseApplLayer{
public:
    void initialize( int stage ) override;
    void finish() override;


    void handleSelfMsg( cMessage* msg ) override;
    void handlePositionUpdate( cObject* obj ) override;
    void startService( veins::Channel channel, int serviceId, std::string serviceDescription ) override;
    void populateWSM( veins::BaseFrame1609_4* wsm, veins::LAddress::L2Type rcvId = -1, int serial = 0 ) override;
    void onWSA( veins::DemoServiceAdvertisment* wsa ) override;
    void onWSM( veins::BaseFrame1609_4* frame ) override;

    // Might get rid of this
    enum class SigAlgo : int
    {
        None,
        MLDSA_65,
        SLH_DSA_192s,
        SLH_DSA_192f
    };
    // And this
    enum class KemAlgo : int
    {
        None,
        MLKEM_768,
        HQC_192
    };

protected:
    simtime_t lastDroveAt;
    bool sentMessage;
    int currentSubscribedServiceId;
    veins::LAddress::L2Type rsuAddr;    //Ugly fix for a problem that slipped my mind
    // KEM
    KemAlgo kemAlgo;
    OQS_KEM* kem = nullptr; //Holds kem instance pointer
    OQS_SIG* sig = nullptr;
    std::vector<uint8_t> kemPublicKey;
    std::vector<uint8_t> kemSecretKey;
    std::map<veins::LAddress::L2Type, std::vector<uint8_t>> sharedSecrets; //Map sender address to a shared secret
    std::map<veins::LAddress::L2Type, std::vector<uint8_t>> kemPublicKeys; //Map sender address to their public key
    // DSA (one static keypair per vehicle)
    SigAlgo signatureAlgo;
    std::vector<uint8_t> sigPublicKey;
    std::vector<uint8_t> sigSecretKey;
    std::vector<uint8_t> signature;

    std::set<std::string> knownBlockedRoads; //To stop repeat handling of message duplicates

    cOutVector signTimeVec;
    cOutVector verTimeVec;
    cOutVector encapsTimeVec;
    cOutVector kpSigGenTimeVec;
    cOutVector kpKemGenTimeVec;
    cOutVector e2eDelayVec;
    cOutVector rsuPkge2eDelayVec;
    cOutVector networkDelayVec;
    cOutVector rsuPkgnetworkDelayVec;
    cOutVector packetSizeVec;


};
}
