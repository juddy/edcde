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
/* $XConsortium: utscr.c /main/2 1996/05/09 04:21:29 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: d_utscr
 *
 *   ORIGINS: 157
 *
 *   OBJECT CODE ONLY SOURCE MATERIALS
 */
/*-----------------------------------------------------------------------
   utscr.c -- db_VISTA current record update timestamp get module.

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
/* Get update timestamp of current record
*/
d_utscr(timestamp TASK_PARM)
ULONG FAR *timestamp;
TASK_DECL
{
   INT rec;
   int dbopen_sv;

   DB_ENTER(NO_DB_ID TASK_ID LOCK_SET(RECORD_IO));

   /* make sure we have a current record */
   if ( ! curr_rec )
      RETURN( dberr(S_NOCR) );

   /* set up to allow unlocked read access */
   dbopen_sv = dbopen;
   dbopen = 2;
   /* read current record */
   if ( dio_read( curr_rec, (char FAR * FAR *)&crloc , NOPGHOLD) != S_OKAY )
      RETURN( db_status );
   dbopen = dbopen_sv;

   /* get record id */
   bytecpy(&rec, crloc, sizeof(INT));
   if ( rec >= 0 ) {
      rec &= ~RLBMASK; /* mask off rlb */
#ifndef	 ONE_DB
      rec += curr_db_table->rt_offset;
#endif
      if ( record_table[rec].rt_flags & TIMESTAMPED )
	 bytecpy(timestamp, crloc + RECUPTIME, sizeof(ULONG));
      else
	 *timestamp = 0L;
      db_status = S_OKAY;
   }
   else
      db_status = S_DELETED;

   RETURN( db_status );
}
#endif
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin utscr.c */
