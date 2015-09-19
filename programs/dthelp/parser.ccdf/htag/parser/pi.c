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
/* $XConsortium: pi.c /main/3 1995/11/08 11:30:02 rswiston $ */
/*
              Copyright 1986 Tandem Computers Incorporated.
This product and information is proprietary of Tandem Computers Incorporated.
                   Copyright 1986, 1987, 1988, 1989 Hewlett-Packard Co.
*/

/* Pi.c executes pi-code specified in the interface. */

#include "userinc.h"
#include "globdec.h"

/* Include generated code */
#include "pfile.c"


/* When a processing instruction or SDATA entity other than a CODE entity
   occurs */
void m_piaction(m_pi, m_entname, m_enttype)
  M_WCHAR *m_pi ;
  M_WCHAR *m_entname ;
  int m_enttype ;
  {
    m_stackpar = m_stacktop->piparam ;
    (*m_ptable[m_stacktop->picase])(m_pi, m_entname, m_enttype) ;
    }

