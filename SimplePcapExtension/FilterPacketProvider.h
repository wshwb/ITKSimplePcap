//
//  FilterPacketProvider.h
//  SimplePcapExtension
//
//  Created by Yamin Tian on 6/8/20.
//  Copyright © 2020 Demo. All rights reserved.
//

#import <NetworkExtension/NetworkExtension.h>

typedef struct _GVSPPacketHeader{
    
    uint16_t status;
    uint16_t block_id;
    uint8_t Erp;
    uint8_t packet_id[3];
}GVSPPacketHeader;

//gogal varibale about received packet count and lost packet count
uint32_t lastRcvPktId=0;
uint32_t lastRcvBlkId=0;
uint32_t totalRcvpktCount=0;
uint32_t totalLostPktCount=0;

@interface FilterPacketProvider : NEFilterPacketProvider

//return true if drop this packet; return false if allow this pacekt
+ (bool)handlePacketwithContext: (NEFilterPacketContext *_Nonnull) context
                  fromInterface: (nw_interface_t _Nonnull) interface
                      direction: (NETrafficDirection) direction
                   withRawBytes: (const void *_Nonnull) packetBytes
                         length: (const size_t) packetLength;

@end
