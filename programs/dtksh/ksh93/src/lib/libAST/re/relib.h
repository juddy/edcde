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
/* $XConsortium: relib.h /main/3 1995/11/01 18:22:46 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
*                                                              *
***************************************************************/

/* : : generated by proto : : */
                  
/*
 * AT&T Bell Laboratories
 *
 * regular expression library private definitions
 */

#ifndef _RELIB_H
#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif

#define _RELIB_H

#include <ast.h>

#define NCLASS		16		/* max # [...] expressions	*/
#define NMATCH		('9'-'0'+1)	/* max # (...) expressions	*/

typedef struct			/* sub-expression match			*/
{
	char*	sp;		/* start in source string		*/
	char*	ep;		/* end in source string			*/
} Match_t;

typedef struct			/* sub-expression match table		*/
{
	Match_t	m[NMATCH + 1];
} Subexp_t;

typedef struct			/* character class bit vector		*/
{
	char		map[UCHAR_MAX / CHAR_BIT + 1];
} Class_t;

typedef struct Inst		/* machine instruction			*/
{
	int		type;	/* <TOKEN ==> literal, otherwise action	*/
	union
	{

	int		sid;	/* sub-expression id for RBRA and LBRA	*/
	struct Inst*	other;	/* for right child			*/
	char*		cls;	/* CCLASS bit vector			*/

	} u;
	struct Inst*	left;	/* left child				*/
} Inst_t;

/*
 * NOTE: subexp must be the first element to match Re_program_t.match
 */

#define _RE_PROGRAM_PRIVATE_ \
	Subexp_t	subexp;		/* sub-expression matches	*/ \
	int		flags;		/* RE_* flags			*/ \
	Inst_t*		startinst;	/* start pc			*/ \
	Class_t		chrset[NCLASS];	/* .data			*/ \
	Inst_t		firstinst[5];	/* .text			*/

#include <re.h>

#define clrbit(set,bit)	(set[(bit)/CHAR_BIT]&=~(1<<((bit)%CHAR_BIT)))
#define setbit(set,bit)	(set[(bit)/CHAR_BIT]|=(1<<((bit)%CHAR_BIT)))
#define tstbit(set,bit)	((set[(bit)/CHAR_BIT]&(1<<((bit)%CHAR_BIT)))!=0)

#define	next	left
#define	subid	u.sid
#define right	u.other
#define cclass	u.cls

/*
 * tokens and actions
 *
 *	TOKEN<=x<OPERATOR are tokens, i.e. operands for operators
 *	>=OPERATOR are operators, value == precedence
 */

#define TOKEN		(UCHAR_MAX+1)
#define	ANY		(UCHAR_MAX+1)	/* `.' any character		*/
#define	NOP		(UCHAR_MAX+2)	/* no operation (internal)	*/
#define	BOL		(UCHAR_MAX+3)	/* `^' beginning of line	*/
#define	EOL		(UCHAR_MAX+4)	/* `$' end of line		*/
#define	BID		(UCHAR_MAX+5)	/* `\<' begin identifier	*/
#define	EID		(UCHAR_MAX+6)	/* `\>' end identifier		*/
#define	CCLASS		(UCHAR_MAX+7)	/* `[]' character class		*/
#define SUBEXPR		(UCHAR_MAX+8)	/* `\#' sub-expression		*/
#define	END		(UCHAR_MAX+9)	/* terminate: match found	*/

#define	OPERATOR	(UCHAR_MAX+11)
#define	START		(UCHAR_MAX+11)	/* start, stack marker		*/
#define	RBRA		(UCHAR_MAX+12)	/* `)' right bracket		*/
#define	LBRA		(UCHAR_MAX+13)	/* `(' left bracket		*/
#define	OR		(UCHAR_MAX+14)	/* `|' alternation		*/
#define	CAT		(UCHAR_MAX+15)	/* concatentation (implicit)	*/
#define	STAR		(UCHAR_MAX+16)	/* `*' closure			*/
#define	PLUS		(UCHAR_MAX+17)	/* a+ == aa*			*/
#define	QUEST		(UCHAR_MAX+18)	/* a? == 0 or 1 a's		*/

#endif
