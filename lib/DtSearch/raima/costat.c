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
/* $XConsortium: costat.c /main/2 1996/05/09 03:56:57 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_costat
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   costat.c -- db_VISTA owner timestamp status check module.

   (C) Copyright 1987 by Raima Corporation.
-----------------------------------------------------------------------*/

/* ********************** EDIT HISTORY *******************************

 SCR    DATE    INI                   DESCRIPTION
----- --------- --- -----------------------------------------------------
      04-Aug-88 RTK MULTI_TASK changes
*/

#include <stdio.h>
#include "vista.h"
#include "dbtype.h"


#ifndef	 NO_TIMESTAMP
/* Test timestamp status of current owner
*/
d_costat(set TASK_PARM DBN_PARM)
int set;
TASK_DECL
DBN_DECL
{
   ULONG cts, uts;
   ULONG cots;

   DB_ENTER(DB_ID TASK_ID LOCK_SET(SET_IO));

   if ( d_ctsco(set, &cts TASK_PARM DBN_PARM) == S_OKAY ) {
      if ( cts ) {
	 cots = co_time[NUM2INT(set - SETMARK, st_offset)];
	 if ( cts > cots )
	    db_status = S_DELETED;
	 else {
	    d_utsco(set, &uts TASK_PARM DBN_PARM);
	    if ( uts > cots )
	       db_status = S_UPDATED;
	 }
      }
      else
	 dberr(S_TIMESTAMP);
   }
   RETURN( db_status );
}
#endif
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin costat.c */
