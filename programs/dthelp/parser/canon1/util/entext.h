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
/* $XConsortium: entext.h /main/3 1995/11/08 09:50:14 rswiston $ */
/* Copyright (c) 1988, 1989 Hewlett-Packard Co. */
/* Entext.h contains the dtd- and interface-independent external
forms of declarations relevant to entity declarations that occur in a
dtd or interface.   The definition form of these declarations is
contained in files entity.h generated by BUILD and entity2.h
generated by ELTDEF */

#include "entdef.h"
extern M_WCHAR m_entcon[] ;

extern M_WCHAR m_entname[] ;

extern M_ENTITY m_entities[] ;

extern M_TRIE m_enttrie[] ;

#if defined(ELTEXTERN)
extern int m_entcnt ;
extern M_ENTITY *firstent ;
extern M_ENTITY *lastent ;
#endif
