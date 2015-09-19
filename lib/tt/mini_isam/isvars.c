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
/*%%  $XConsortium: isvars.c /main/3 1995/10/23 11:45:48 rswiston $ 			 				 */
#ifndef lint
static char sccsid[] = "@(#)isvars.c 1.7 90/08/15 Copyr 1988 Sun Micro";
#endif
/*
 * Copyright (c) 1988 by Sun Microsystems, Inc.
 */

/*
 * isvars.c
 *
 * Description:
 *	NetISAM gloabl variables
 *
 */

#include "isam_impl.h"

int iserrno;
int isreclen;
long isrecnum;

char   isstat1, isstat2, isstat3, isstat4;

static struct keydesc _nokey;
struct keydesc *nokey = &_nokey;

/* 
 * isdupl is used internally to indicate that some index contains
 * a duplicate value. Used only to set up isstat2 Cobol variable.
 */

int isdupl;				     /* 1 if duplicate found */

