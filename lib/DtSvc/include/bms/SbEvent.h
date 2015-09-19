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
/*
 * File:         SbEvent.h $XConsortium: SbEvent.h /main/3 1995/10/26 15:45:29 rswiston $
 * Language:     C
 *
 * (c) Copyright 1990, Hewlett-Packard Company, all rights reserved.
 *
 * (c) Copyright 1993, 1994 Hewlett-Packard Company			*
 * (c) Copyright 1993, 1994 International Business Machines Corp.	*
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.			*
 * (c) Copyright 1993, 1994 Novell, Inc.				*
 */

#ifndef _SbEvent_h
#define _SbEvent_h

typedef unsigned long SbInputId;

typedef void (*SbInputCallbackProc)
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
   (void* data, int *fd, SbInputId *id);
#else
   ();
#endif
    
extern SbInputId (*SbAddInput_hookfn)
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
    (int fd, SbInputCallbackProc proc, void* data);
#else
    ();
#endif
    
extern SbInputId (*SbAddException_hookfn)
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
    (int fd, SbInputCallbackProc proc, void* data);
#else
   ();
#endif

extern void  (*SbRemoveInput_hookfn)    
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
   (SbInputId id);
#else
   ();
#endif

extern void  (*SbRemoveException_hookfn)
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
   (SbInputId id);
#else
   ();
#endif

extern void  (*SbMainLoopUntil_hookfn)  
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
   (Boolean *flag);
#else
   ();
#endif

extern void XeCall_SbMainLoopUntil
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
   (Boolean *flag);
#else
   ();
#endif

extern void  (*SbBreakMainLoop_hookfn)  
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
   (void);
#else
   ();
#endif


#endif /* _SbEvent_h */
