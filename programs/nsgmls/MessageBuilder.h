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
/* $XConsortium: MessageBuilder.h /main/1 1996/07/29 16:57:19 cde-hp $ */
// Copyright (c) 1994 James Clark
// See the file COPYING for copying permission.

#ifndef MessageBuilder_INCLUDED
#define MessageBuilder_INCLUDED 1

#include <stddef.h>
#include "types.h"

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

class OtherMessageArg;
class MessageFragment;

class SP_API MessageBuilder {
public:
  virtual void appendNumber(unsigned long) = 0;
  virtual void appendOrdinal(unsigned long) = 0;
  virtual void appendChars(const Char *, size_t) = 0;
  virtual void appendOther(const OtherMessageArg *) = 0;
  virtual void appendFragment(const MessageFragment &) = 0;
};

#ifdef SP_NAMESPACE
}
#endif

#endif /* not MessageBuilder_INCLUDED */
