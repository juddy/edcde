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
/* $XConsortium: Id.h /main/1 1996/07/29 16:54:38 cde-hp $ */
// Copyright (c) 1994 James Clark
// See the file COPYING for copying permission.

#ifndef Id_INCLUDED
#define Id_INCLUDED 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Named.h"
#include "Location.h"
#include "Vector.h"

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

class Id : public Named {
public:
  Id(const StringC &);
  void define(const Location &);
  void addPendingRef(const Location &);
  Boolean defined() const;
  const Location &defLocation() const;
  const Vector<Location> &pendingRefs() const;
private:
  Location defLocation_;
  Vector<Location> pendingRefs_;
};

inline
Boolean Id::defined() const
{
  return !defLocation_.origin().isNull();
}

inline
const Location &Id::defLocation() const
{
  return defLocation_;
}

inline
const Vector<Location> &Id::pendingRefs() const
{
  return pendingRefs_;
}

inline
void Id::addPendingRef(const Location &loc)
{
  pendingRefs_.push_back(loc);
}

#ifdef SP_NAMESPACE
}
#endif

#endif /* not Id_INCLUDED */
