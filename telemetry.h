/*
 * Copyright (c) 2011-2012, Regents of the University of California
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the University of California, Berkeley nor the names
 *   of its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * Telemetry packet formats
 *
 * by Humphrey Hu
 *
 * v. beta
 */
 #ifndef __TELEMETRY_H
 #define __TELEMETRY_H

#include "bams.h"
#include "quat.h"

// Sensor Telemetry Packet (Type A)
#define TELEMETRY_A_SIZE	(6)
typedef struct {
    unsigned long time;     // (4) Local time
    int gyro[3];            // (6) Raw gyro values
    int xl[3];              // (6) Raw xl values
} TelemetryStructA;
typedef TelemetryStructA* TelemetryA;
 
// State Telemetry Packet (Type B)
#define TELEMETRY_B_SIZE	(40)
typedef struct {
    unsigned long time;     // (4) Local time
    //bams16_t pose[3];     // (6) Euler angles in BAMS format (Switch to quaternions?)
    float ref[3];           // (12) Reference
    float x[3];             // (12) Position
    float u[3];             // (12) Output
} TelemetryStructB;
typedef TelemetryStructB* TelemetryB;

#define TELEMETRY_ATT_SIZE  (16)
typedef struct {
    Quaternion att;
} TelemetryStructAttitude;
typedef TelemetryStructAttitude* TelemetryAttitude;

// Send a type A telemetry packet
void telemSendA(unsigned int addr);

// Send a type B telemetry packet
void telemSendB(unsigned int addr);

// Send an attitude report packet
void telemSendAttitude(unsigned int addr);

#endif

