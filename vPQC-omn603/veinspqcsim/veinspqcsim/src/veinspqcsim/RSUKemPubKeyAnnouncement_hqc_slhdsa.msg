//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

import veins.base.utils.Coord;
import veins.modules.messages.BaseFrame1609_4;
import veins.base.utils.SimpleAddress;

namespace veinspqcsim;

packet RSUKemPubKeyAnnouncement_hqc_slhdsa extends veins::BaseFrame1609_4 {
    int messageId = 0;				// RSU = 0, CAR = 1
    veins::LAddress::L2Type senderAddress = -1;
    simtime_t generationTime;			// Time of original message creation
    double signingTime;					// Needed for e2e delay in place of messier solutions
    uint8_t signature[35664];     		// signature
    uint8_t pubKey[48];					// signature public key
    uint8_t kemPublicKey[4522];			// HQC
    int sigType;
    int kemType;
    double lat;
    double lon;
}