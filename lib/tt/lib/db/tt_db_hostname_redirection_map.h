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
/*%%  $XConsortium: tt_db_hostname_redirection_map.h /main/3 1995/10/23 10:02:51 rswiston $ 			 				 */
/* @(#)tt_db_hostname_redirection_map.h	1.5 @(#)
 * Tool Talk Utility - tt_hostname_redirection_map.h
 *
 * Copyright (c) 1990 by Sun Microsystems, Inc.
 *
 * Declares a hostname redirection map.  A global version
 * of this object is in _tt_global.
 */

#ifndef _TT_HOSTNAME_REDIRECTION_MAP_H
#define _TT_HOSTNAME_REDIRECTION_MAP_H

#include "util/tt_object.h"
#include "util/tt_string_map_utils.h"
#include "util/tt_string_map.h"
#include "util/tt_map_entry.h"

class _Tt_db_hostname_redirection_map : public _Tt_object {
public:
  _Tt_db_hostname_redirection_map ();
  ~_Tt_db_hostname_redirection_map ();

  void refresh ();
  _Tt_string findEntry(const _Tt_string &address);

private:
  _Tt_string_map_ptr map;
};

#endif /* _TT_HOSTNAME_REDIRECTION_MAP_H */
