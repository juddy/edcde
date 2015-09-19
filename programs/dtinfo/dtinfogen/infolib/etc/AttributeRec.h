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
/* $XConsortium: AttributeRec.h /main/3 1996/08/21 15:46:05 drk $ */

//----------------------------------------------
// AttributeRec.h

#ifndef ATT_REC_HDR
#define ATT_REC_HDR

#include "SGMLName.h"

class SGMLDefn;

class AttributeRec {

friend class OL_AttributeList;
friend class Token;
  
private:
  
  int attName;
  int attType;
  const char *attValueString;
  char  *copy;
  int  attValue;
  AttributeRec *next;
  
protected:
  AttributeRec( const char * name, const char *value,
		int type );
  ~AttributeRec();

public:  
  int getAttrName() const;

  /* use this for CDATA attributes */
  const char *getAttrValueString() const { return(attValueString); }

  /* use this for NAME, NOTATION, ENTITY attributes */
  int   getAttValue()        const    { return(attValue); } 

  int getAttrType() const    { return(attType); }

  int operator== ( AttributeRec & s ) {
    return ( attName == s.attName );
  }
};

#endif
