/********************************************
sizes.h
copyright 2009,2010.  Thomas E. Dickey
copyright 1991-1995,2014.  Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 2, 1991.
********************************************/

/*
 * $MawkId: sizes.h,v 1.10 2014/08/14 23:34:44 mike Exp $
 * @Log: sizes.h,v @
 * Revision 1.8  1995/10/14  22:09:51  mike
 * getting MAX__INT from values.h didn't really work since the value was
 * unusable in an #if MAX__INT <= 0x7fff
 * at least it didn't work under sunos -- so use of values.h is a goner
 *
 * Revision 1.7  1995/06/18  19:17:51  mike
 * Create a type Int which on most machines is an int, but on machines
 * with 16bit ints, i.e., the PC is a long.  This fixes implicit assumption
 * that int==long.
 *
 * Revision 1.6  1994/10/10  01:39:01  mike
 * get MAX__INT from limits.h or values.h
 *
 * Revision 1.5  1994/10/08  19:15:53  mike
 * remove SM_DOS
 *
 * Revision 1.4  1994/09/25  23:00:49  mike
 * remove #if 0
 *
 * Revision 1.3  1993/07/15  23:56:15  mike
 * general cleanup
 *
 * Revision 1.2  1993/07/04  12:52:13  mike
 * start on autoconfig changes
 *
 * Revision 5.3  1992/12/17  02:48:01  mike
 * 1.1.2d changes for DOS
 *
 * Revision 5.2  1992/08/27  03:20:08  mike
 * patch2: increase A_HASH_PRIME
 *
 * Revision 5.1  1991/12/05  07:59:35  brennan
 * 1.1 pre-release
 *
*/

/*  sizes.h  */

#ifndef  SIZES_H
#define  SIZES_H

#include "config.h"

#ifndef MAX__INT
#include <limits.h>
#define  MAX__INT  INT_MAX
#define  MAX__LONG LONG_MAX
#define  MAX__UINT UINT_MAX
#endif /* MAX__INT */

#if  MAX__INT <= 0x7fff
#define  SHORT_INTS
#define  INT_FMT "%ld"
typedef long Int;
#define  Max_Int MAX__LONG
#else
#define  INT_FMT "%d"
typedef int Int;
#define  Max_Int  MAX__INT
#endif

#if  MAX__UINT <= 0xffff
#define  SHORT_UINTS
#define  UINT_FMT "%lu"
typedef unsigned long UInt;
#define  Max_UInt MAX__ULONG
#else
#define  UINT_FMT "%u"
typedef unsigned UInt;
#define  Max_UInt  MAX__UINT
#endif

#define EVAL_STACK_SIZE  256	/* initial size , can grow */

/*
 * FBANK_SZ, the number of fields at startup, must be a power of 2.
 *
 */
#define  FBANK_SZ	1024
#define  FB_SHIFT	  10	/* lg(FBANK_SZ) */

/*
 * hardwired limit on sprintf size, can be overridden with -Ws=xxx
 * TBD to remove hard wired limit
 */
#define  SPRINTF_LIMIT	8192

#define  BUFFSZ         4096
  /* starting buffer size for input files, grows if
     necessary */

#ifdef  MSDOS
/* trade some space for IO speed */
#undef  BUFFSZ
#define BUFFSZ		8192
/* maximum input buffers that will fit in 64K */
#define  MAX_BUFFS	((int)(0x10000L/BUFFSZ) - 1)
#endif

#define  HASH_PRIME  53
#define  A_HASH_PRIME 199

#define  MAX_COMPILE_ERRORS  5	/* quit if more than 4 errors */

#endif /* SIZES_H */
