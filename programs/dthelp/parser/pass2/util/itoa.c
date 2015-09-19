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
/* $XConsortium: itoa.c /main/3 1995/11/08 11:06:09 rswiston $ */
/* From example in Kernighan and Ritchie, The C Programming Language,
   Prentice-Hall, 1978 */

#include <string.h>
#include "basic.h"

char *m_itoa(
#if defined(M_PROTO)
  int n, char *s
#endif
  ) ;

void reverse(
#if defined(M_PROTO)
  char *s
#endif
  ) ;

char *m_itoa(n, s)  /* convert n to characters in s */
char s[]; 
int n;
{   
    int sign ;
    char *p = s ;

    if ( (sign = n) < 0 ) /* record sign */
        n = -n;
    do {    /* generate digits in reverse order */
        *p++ = (char) (n % 10 + '0') ;
    }  while (( n/= 10) > 0);
    if (sign < 0)
        *p++ = '-';
    *p = '\0';

    reverse(s);
    return(s) ;
}

void reverse(s)
char s[];
{
    int c, i, j;

    for (i=0, j=strlen(s)-1; i < j ; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = (char) c;
    }
}
