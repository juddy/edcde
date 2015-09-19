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
/* $XConsortium: AsciiSpcI.h /main/4 1995/10/26 12:17:10 rswiston $ */
/*************************************<+>*************************************
 *****************************************************************************
 **
 **  File:   AsciiSpcI.h
 **
 **  Project:
 **
 **  Description:  Public Header file for AsciiSpc.c
 **
 **  (c) Copyright 1987, 1988, 1989, 1990, 1991, 1992 Hewlett-Packard Company
 **
 **  (c) Copyright 1993, 1994 Hewlett-Packard Company
 **  (c) Copyright 1993, 1994 International Business Machines Corp.
 **  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 **  (c) Copyright 1993, 1994 Novell, Inc.
 *******************************************************************
 *************************************<+>*************************************/
#ifndef _DtHelpAsciiSpc_h
#define _DtHelpAsciiSpc_h


#ifdef __cplusplus
extern "C" {
#endif

/********    Public Defines Declarations    ********/

/********    Public Typedef Declarations    ********/

/********    Public Structures Declarations    ********/

/********    Public Macro Declarations    ********/

/********    Semi-Private Function Declarations    ********/
extern	const char	*_DtHelpCeResolveSpcToAscii(
				const char	*spc_symbol);

#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif


#endif /* _DtHelpAsciiSpc_h */
/* DON'T ADD ANYTHING AFTER THIS #endif */
