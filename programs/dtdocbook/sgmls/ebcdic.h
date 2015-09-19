/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these librararies and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: ebcdic.h /main/3 1996/06/19 17:14:42 drk $ */
/* SGML Character Use: EBCDIC
*/

#define EOFCHAR   '\077'      /* FUNCTION: EE (entity end: files). */
#define EOBCHAR   '\034'      /* NONCHAR: EOB (file entity: end of buffer. */
#define RSCHAR    '\045'      /* FUNCTION: RS (record start). */
#define RECHAR    '\015'      /* FUNCTION: RE (record end). */
#define TABCHAR   '\005'      /* FUNCTION: TAB (horizontal tab). */
#define SPCCHAR   '\100'      /* FUNCTION: SPACE (horizontal space). */
#define GENRECHAR '\026'      /* NONCHAR: Generated RE. */
#define DELCDATA  '\035'      /* NONCHAR: Delimiter for CDATA entity in
				 attribute value. */
#define DELSDATA  '\036'      /* NONCHAR: Delimiter for SDATA entity in
				 attribute value. */
#define DELNONCH  '\037'      /* NONCHAR: non-SGML character prefix. */

/* This should work for EBCDIC.  See comment in latin1.h. */
#define SHIFTNON(ch) ((UNCH)(ch) | 0200)
#define UNSHIFTNON(ch) ((UNCH)(ch) & ~0200)

/* See comment in latin1.h. */
#define CANON_NONSGML 255

/* See comment in latin1.h. */
#define CANON_DATACHAR 254

/* Components for a formal public identifier for the whole of the
system character set.  Protect with ifndef so that it can be overriden
in config.h. */

/* Use a private escape sequence. */
#ifndef SYSTEM_CHARSET_DESIGNATING_SEQUENCE
#define SYSTEM_CHARSET_DESIGNATING_SEQUENCE "ESC 2/5 2/15 3/0"
#endif
#ifndef SYSTEM_CHARSET_OWNER
#define SYSTEM_CHARSET_OWNER "-//IBM"
#endif
#ifndef SYSTEM_CHARSET_DESCRIPTION
#define SYSTEM_CHARSET_DESCRIPTION "Code Page 1047"
#endif
