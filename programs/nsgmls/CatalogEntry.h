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
/* $XConsortium: CatalogEntry.h /main/1 1996/07/29 16:46:56 cde-hp $ */
// Copyright (c) 1994, 1995 James Clark
// See the file COPYING for copying permission.

#ifndef CatalogEntry_INCLUDED
#define CatalogEntry_INCLUDED 1

#include "Location.h"
#include "StringC.h"
#include <stddef.h>

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

struct CatalogEntry {
  StringC to;
  Location loc;
  size_t catalogNumber;
  size_t baseNumber;
  size_t serial;
};

#ifdef SP_NAMESPACE
}
#endif

#endif /* not CatalogEntry_INCLUDED */
