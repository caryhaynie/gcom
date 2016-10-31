/*
* genuuid.h
* Dolphin Release 0.5.0
*
* Copyright (c) 1999 Samuel A. Falvo II
* All Rights Reserved.
*
* This program generates UUIDs according to the method documented in the
* IETF draft-standard on UUIDs.  Please refer to
* draft-leach-uuids-guids-01.txt.
*/

#ifndef GENUUID_H
#define GENUUID_H

#include <stdio.h>
#if defined(__APPLE__) && defined(__clang__)
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#endif // defined(__APPLE__) && defined(__clang__)
#include "gcom-config.h"

/* This is the offset from the time reference between gettimeofday()
* (Jan 1 1970 UTC), and that required for UUIDs (Jan 1, 1582 UTC).
*/

const unsigned long long time_offset = 122443488000000000LL;

/* For now, we hardcode the developers Ethernet address into this node
* structure.	In the future, we will need to fetch this either automatically
* or via a configuration file.
*/

static char node[6] = { 0x00, 0x00, 0x01, 0x13, 0x56, 0x27 };

typedef struct
{
	unsigned long	time_lo;
	unsigned short	time_mid;
	unsigned short	time_hi;	/* and version */
	unsigned char	clockseq_hi;	/* I'd SURE like to know why... */
	unsigned char	clockseq_lo;	/* this is big-endian. */
	unsigned char	node[6];
} UUID;

UUID id;

#endif /* GENUUID_H */