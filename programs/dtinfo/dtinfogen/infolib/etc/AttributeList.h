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
/* $XConsortium: AttributeList.h /main/3 1996/08/21 15:46:01 drk $ */
//---------------------------------------------------------
// AttributeList.h

#ifndef ATT_LIST_HDR
#define ATT_LIST_HDR

#include <stdio.h>
#include "AttributeRec.h"


class OL_AttributeList {

friend class Token;
  
protected:
  AttributeRec *head;
  AttributeRec *tail;

  AttributeRec *lookup ( int ) const;
  void  insert(AttributeRec * );

  const AttributeRec *GetFirstAttr() const;
  const AttributeRec *GetNextAttr( const AttributeRec *) const;
  OL_AttributeList();
  ~OL_AttributeList();
};

#endif


  
