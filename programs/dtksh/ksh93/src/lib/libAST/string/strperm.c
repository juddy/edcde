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
/* $XConsortium: strperm.c /main/3 1995/11/01 18:50:21 rswiston $ */
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
#include <ast.h>
#include <ls.h>
#include <modex.h>

int
strperm __PARAM__((const char* aexpr, char** e, register int perm), (aexpr, e, perm)) __OTORP__(const char* aexpr; char** e; register int perm;){
	register char*	expr = (char*)aexpr;
	register int	c;
	register int	typ;
	register int	who;
	int		num;
	int		op;

	for (;;)
	{
		op = num = who = typ = 0;
		for (;;)
		{
			switch (c = *expr++)
			{
			case 'u':
				who |= S_ISVTX|S_ISUID|S_IRWXU;
				continue;
			case 'g':
				who |= S_ISVTX|S_ISGID|S_IRWXG;
				continue;
			case 'o':
				who |= S_ISVTX|S_IRWXO;
				continue;
			case 'a':
				who = S_ISVTX|S_ISUID|S_ISGID|S_IRWXU|S_IRWXG|S_IRWXO;
				continue;
			default:
				if (c >= '0' && c <= '7') c = '=';
				expr--;
				/*FALLTHROUGH*/
			case '=':
			case '+':
			case '|':
			case '-':
			case '&':
				op = c;
				for (;;)
				{
					switch (c = *expr++)
					{
					case 'r':
						typ |= S_IRUSR|S_IRGRP|S_IROTH;
						continue;
					case 'w':
						typ |= S_IWUSR|S_IWGRP|S_IWOTH;
						continue;
					case 'X':
						if (op != '+' || !S_ISDIR(perm) && !(perm & (S_IXUSR|S_IXGRP|S_IXOTH))) continue;
						/*FALLTHROUGH*/
					case 'x':
						typ |= S_IXUSR|S_IXGRP|S_IXOTH;
						continue;
					case 's':
						typ |= S_ISUID|S_ISGID;
						continue;
					case 't':
						typ |= S_ISVTX;
						continue;
					case '=':
					case '+':
					case '|':
					case '-':
					case '&':
					case ',':
					case 0:
						if (who) typ &= who;
						switch (op)
						{
						default:
							if (who) perm &= ~who;
							else perm = 0;
							/*FALLTHROUGH*/
						case '+':
						case '|':
							perm |= typ;
							typ = 0;
							break;
						case '-':
							perm &= ~typ;
							typ = 0;
							break;
						case '&':
							perm &= typ;
							typ = 0;
							break;
						}
						switch (c)
						{
						case '=':
						case '+':
						case '|':
						case '-':
						case '&':
							op = c;
							typ = 0;
							continue;
						}
						if (c) break;
						/*FALLTHROUGH*/
					default:
						if (c < '0' || c > '7')
						{
							if (e) *e = expr - 1;
							if (typ)
							{
								if (who)
								{
									typ &= who;
									perm &= ~who;
								}
								perm |= typ;
							}
							return(perm);
						}
						num = (num <<= 3) | (c - '0');
						if (*expr < '0' || *expr > '7')
						{
							typ |= modei(num);
							num = 0;
						}
						continue;
					}
					break;
				}
				break;
			}
			break;
		}
	}
}
