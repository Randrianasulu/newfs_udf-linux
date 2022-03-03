/* $NetBSD: udf_bswap.h,v 1.8 2009/10/22 21:50:01 bouyer Exp $	*/

/*
 * Copyright (c) 1998 Manuel Bouyer.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * adapted for UDF by Reinoud Zandijk <reinoud@netbsd.org>
 *
 */

#ifndef _FS_UDF_UDF_BSWAP_H_
#define _FS_UDF_UDF_BSWAP_H_

#include <sys/endian.h>
// #include <machine/bswap.h>
// #include <sys/bswap.h>
#include <byteswap.h>

#if defined(__TERMUX__) 

static inline uint16_t bswap16(uint16_t x)
{
    return (((x & 0x00ff) << 8) |
            ((x & 0xff00) >> 8));
}

static inline uint32_t bswap32(uint32_t x)
{
    return (((x & 0x000000ffU) << 24) |
            ((x & 0x0000ff00U) <<  8) |
            ((x & 0x00ff0000U) >>  8) |
            ((x & 0xff000000U) >> 24));
}

static inline uint64_t bswap64(uint64_t x)
{
    return (((x & 0x00000000000000ffULL) << 56) |
            ((x & 0x000000000000ff00ULL) << 40) |
            ((x & 0x0000000000ff0000ULL) << 24) |
            ((x & 0x00000000ff000000ULL) <<  8) |
            ((x & 0x000000ff00000000ULL) >>  8) |
            ((x & 0x0000ff0000000000ULL) >> 24) |
            ((x & 0x00ff000000000000ULL) >> 40) |
            ((x & 0xff00000000000000ULL) >> 56));
} 

#endif

/* rest only relevant for big endian machines */
#if (BYTE_ORDER == BIG_ENDIAN)

/* inlines for access to swapped data */
static __inline uint16_t udf_rw16(uint16_t);
static __inline uint32_t udf_rw32(uint32_t);
static __inline uint64_t udf_rw64(uint64_t);


static __inline uint16_t
udf_rw16(uint16_t a)
{
	return bswap16(a);
}


static __inline uint32_t
udf_rw32(uint32_t a)
{
	return bswap32(a);
}


static __inline uint64_t
udf_rw64(uint64_t a)
{
	return bswap64(a);
}

#else

#define udf_rw16(a) ((uint16_t)(a))
#define udf_rw32(a) ((uint32_t)(a))
#define udf_rw64(a) ((uint64_t)(a))

#endif


#endif /* !_FS_UDF_UDF_BSWAP_H_ */

