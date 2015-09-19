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
/*%%  (c) Copyright 1993, 1994 Hewlett-Packard Company			 */
/*%%  (c) Copyright 1993, 1994 International Business Machines Corp.	 */
/*%%  (c) Copyright 1993, 1994 Sun Microsystems, Inc.			 */
/*%%  (c) Copyright 1993, 1994 Novell, Inc. 				 */
/*%%  $XConsortium: iskeycalc.c /main/3 1995/10/23 11:41:29 rswiston $ 			 				 */
#ifndef lint
static char sccsid[] = "@(#)iskeycalc.c 1.3 89/07/17 Copyr 1988 Sun Micro";
#endif
/*
 * Copyright (c) 1988 by Sun Microsystems, Inc.
 */

/*
 * iskeycalc.c
 *
 * Description:
 *	Key related calculation functions
 */

#include "isam_impl.h"


/* getkeysperleaf() - Calculate number of keys per leaf node */
int 
getkeysperleaf (keylen)
    int		keylen;
{
    int 	n;

    n = ((ISPAGESIZE - BT_KEYS_OFF) / keylen);

    return (le_odd (n));		     /* n or n-1 */
}

/* getkeyspernode() - Calculate number of keys per non-leaf node */
int 
getkeyspernode (keylen)
    int		keylen;
{
    int 	n;

    n = ((ISPAGESIZE - BT_KEYS_OFF) / (keylen + BLKNOSIZE));

    return (le_odd (n));		     /* n or n-1 */
}


/* le_odd(n) - Get next lower or equal odd number */
int 
le_odd(n)
    int		n;
{
    return ((n - 1) | 1);
}
