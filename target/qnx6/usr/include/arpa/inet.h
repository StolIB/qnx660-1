/*	$NetBSD: inet.h,v 1.21.10.1 2007/05/17 21:25:11 jdc Exp $	*/

/*
 * ++Copyright++ 1983, 1993
 * -
 * Copyright (c) 1983, 1993
 *    The Regents of the University of California.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * -
 * Portions Copyright (c) 1993 by Digital Equipment Corporation.
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies, and that
 * the name of Digital Equipment Corporation not be used in advertising or
 * publicity pertaining to distribution of the document or software without
 * specific, written prior permission.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 * -
 * --Copyright--
 */

/*%
 *	@(#)inet.h	8.1 (Berkeley) 6/2/93
 *	Id: inet.h,v 1.2.18.1 2005/04/27 05:00:50 sra Exp
 */

#ifndef _ARPA_INET_H_INCLUDED
#define	_ARPA_INET_H_INCLUDED

/* External definitions for functions in inet(3) */
#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif

#ifndef _NETINET_IN_H_INCLUDED
#include <netinet/in.h>
#endif

#ifndef _INTTYPES_H_INCLUDED
#include <inttypes.h>
#endif

#ifdef __EXT_BSD
#ifndef __TYPES_H_INCLUDED
#include <sys/types.h>
#endif
#endif

#ifndef _NET_NETBYTE_H_INCLUDED
#include <net/netbyte.h>  /* for htonl() and friends */
#endif

__BEGIN_DECLS

#if defined(__EXT_POSIX1_200112) || defined(__EXT_BSD)
#if defined(__SOCKLEN_T)
typedef __SOCKLEN_T socklen_t;
#undef __SOCKLEN_T
#endif
#endif

in_addr_t	 inet_addr(const char *);
in_addr_t	 inet_lnaof(struct in_addr);
struct in_addr	 inet_makeaddr(in_addr_t, in_addr_t);
in_addr_t	 inet_netof(struct in_addr);
in_addr_t	 inet_network(const char *);
char		*inet_ntoa(struct in_addr);
#ifdef __EXT_QNX
char		*inet_ntoa_r(struct in_addr, char *, int);
#endif
#if defined(__EXT_POSIX1_200112) || defined(__EXT_BSD)
const char	*inet_ntop(int, const void * __restrict,
		                char * __restrict, socklen_t);
int		 inet_pton(int, const char * __restrict,
		                void * __restrict);
#endif
#ifdef __EXT_BSD
int		 inet_aton(const char *, struct in_addr *);
char *		 inet_neta(unsigned long, char *, size_t);
char		*inet_net_ntop(int, const void *, int, char *, size_t);
int		 inet_net_pton(int, const char *, void *, size_t);
char		*inet_cidr_ntop(int, const void *, int, char *, size_t);
int		 inet_cidr_pton(int, const char *, void *, int *);
unsigned int	 inet_nsap_addr(const char *, unsigned char *, int);
char            *inet_nsap_ntoa(int, const unsigned char *, char *);
#endif
__END_DECLS

#endif /* _ARPA_INET_H_INCLUDED */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn/product/branches/6.6.0/trunk/lib/socket/public/arpa/inet.h $ $Rev: 680336 $")
#endif
