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
/* $XConsortium: setpar.c /main/3 1995/11/08 09:43:12 rswiston $ */
/*
                   Copyright 1986, 1987, 1988, 1989 Hewlett-Packard Co.
*/

/* Setparam.c is used by interfaces where code accesses an element's
   attributes */

#include <stdio.h>
#include "basic.h"
#include "trie.h"
#include "dtdext.h"
#include "parser.h"

/* Set a user-defined C variable to the corresponding parameter value */
void m_setparam(cvar, par)
  M_WCHAR **cvar ;
  int par ;
  {
    *cvar = m_stackpar->param[par] ;
    }

