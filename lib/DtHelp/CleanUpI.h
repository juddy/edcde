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
/* $XConsortium: CleanUpI.h /main/8 1996/01/29 12:19:46 cde-hp $ */
/************************************<+>*************************************
 ****************************************************************************
 **  File:   CleanUpI.h
 **  Project: Common Desktop Environment
 **
 **  (c) Copyright 1993, 1994 Hewlett-Packard Company
 **  (c) Copyright 1993, 1994 International Business Machines Corp.
 **  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 **  (c) Copyright 1993, 1994 Novell, Inc.
 **
 ****************************************************************************
 ************************************<+>*************************************/
#ifndef _DtHelpCleanUpI_h
#define _DtHelpCleanUpI_h

/********    Public Function Declarations    ********/
extern	void	_DtHelpFreeSegments(
				_DtCvSegment	*seg_list,
				_DtCvStatus	 unresolved,
				void		(*destroy_region)(),
				_DtCvPointer	 client_data);
extern	void	_DtHelpDestroyTopicData(
				_DtCvTopicPtr	 topic,
				void 		(*destroy_region)(),
				_DtCvPointer	 client_data);
/********    End Public Function Declarations    ********/

#endif /* _DtHelpCleanUpI_h */
