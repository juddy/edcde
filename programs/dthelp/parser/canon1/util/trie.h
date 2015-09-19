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
/* $XConsortium: trie.h /main/3 1995/11/08 09:55:25 rswiston $ */
/*
                   Copyright 1986, 1987, 1988, 1989 Hewlett-Packard Co.
*/

/* Trie.h contains definitions relating to trees used to store
   element names, delimiter strings, short reference strings, etc. */

/* The data structure described here is not a true trie as described
   in Knuth, Vol. 3.  These functions represent entries by a tree
   structure in which there is one level of subnode for each letter
   in an entry.  In a trie, subnodes are not needed as soon as a
   unique prefix has been encountered. */

typedef struct m_trie M_TRIE ;

typedef struct m_ptrie M_PTRIE ;

struct m_trie {
  M_WCHAR symbol ;
  M_TRIE *next ;
  M_TRIE *data ;
  } ;

struct m_ptrie {
  LOGICAL more ;
  M_WCHAR symbol ;
  int index ;
  } ;


M_TRIE *m_gettrienode(
#if defined(M_PROTO)
  M_NOPAR
#endif
  ) ;

void *m_lookfortrie(
#if defined(M_PROTO)
  const M_WCHAR *p, const M_TRIE *xtrie
#endif
  ) ;

void *m_ntrtrie(
#if defined(M_PROTO)
  M_WCHAR *p, M_TRIE *xtrie, void *dataval
#endif
  ) ;

void *m_resettrie(
#if defined(M_PROTO)
  M_TRIE *xtrie, M_WCHAR *p, void *value
#endif
  ) ;
