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
/* $XConsortium: startdoc.c /main/3 1995/11/08 10:59:27 rswiston $ */
/*
Copyright 1989 Hewlett-Packard Co.
*/

#include "userinc.h"
#include "globdec.h"

/* Default function called at start of document instance.  Allows interface
   control after all entity declarations have been processed.  Not needed
   in valid documents (when it is called just prior to global start-code),
   but may be useful in some applications nevertheless. */
void m_startdoc(M_NOPAR)
  {
    }


