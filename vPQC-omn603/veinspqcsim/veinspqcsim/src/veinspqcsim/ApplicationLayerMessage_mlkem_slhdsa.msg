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

packet ApplicationLayerMessage_mlkem_slhdsa extends veins::BaseFrame1609_4 {
	int messageId = 1;                
	int serial;
	veins::LAddress::L2Type senderAddress = -1;
    simtime_t generationTime;			// Time of original message creation
    simtime_t lastTxTime;				// The msg is a duplicate and this is the time of forwarding
    double signingTime;					// Needed for e2e delay in place of messier solutions
    double encapsTime;
    double lat;							// y
    double lon;							// x
    double speed;
    double heading;						// rad
	string roadId;
    // PQC fields 
    uint8_t signature[35664];     		// signature SLH-DSA
    uint8_t pubKey[48];					// public key SLH-DSA
    //int kemCiphertextLen;
    uint8_t kemCiphertext[1088];  		// ml-kem
    uint8_t kemPublicKey[1184];			// ml-kem
  

    int sigType;
    int kemType;
}