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
/* $XConsortium: URLStorage.h /main/1 1996/07/29 17:07:06 cde-hp $ */
// Copyright (c) 1995 James Clark
// See the file COPYING for copying permission.

#ifndef URLStorage_INCLUDED
#define URLStorage_INCLUDED 1
#ifdef __GNUG__
#pragma interface
#endif

#include "StorageManager.h"

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

class SP_API URLStorageManager : public IdStorageManager {
public:
  URLStorageManager(const char *type);
  StorageObject *makeStorageObject(const StringC &id,
				   const StringC &baseId,
				   Boolean search,
				   Boolean mayRewind,
				   Messenger &,
				   StringC &found); 
  const char *type() const;
  Boolean guessIsId(const StringC &, const CharsetInfo &) const;
  Boolean transformNeutral(StringC &, Boolean fold, Messenger &) const;
private:
  Boolean resolveRelative(const StringC &base, StringC &specId, Boolean) const;
  URLStorageManager(const URLStorageManager &); // undefined
  void operator=(const URLStorageManager &);	// undefined
  const char *type_;
};

#ifdef SP_NAMESPACE
}
#endif

#endif /* not URLStorage_INCLUDED */
