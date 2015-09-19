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
 * $XConsortium: WXmPanedWindow.h /main/3 1996/06/11 17:01:22 cde-hal $
 *
 * Copyright (c) 1991 HaL Computer Systems, Inc.  All rights reserved.
 * UNPUBLISHED -- rights reserved under the Copyright Laws of the United
 * States.  Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 * 
 * This software contains confidential information and trade secrets of HaL
 * Computer Systems, Inc.  Use, disclosure, or reproduction is prohibited
 * without the prior express written permission of HaL Computer Systems, Inc.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(l)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 *                        HaL Computer Systems, Inc.
 *                  1315 Dell Avenue, Campbell, CA  95008
 * 
 */

// This code is automatically generated in -*- C++ -*-
#ifndef WXmPanedWindow_h
#define WXmPanedWindow_h

#include "WXmManager.h"
#include <Xm/PanedW.h>

class WXmPanedWindow : public WXmManager {
public :
        DEFINE_INIT (WXmPanedWindow, WXmManager, xmPanedWindowWidgetClass)
	DEFINE_GETTER_SETTER (MarginWidth,short,"marginWidth")
	DEFINE_GETTER_SETTER (MarginHeight,short,"marginHeight")
	DEFINE_GETTER_SETTER (Spacing,Dimension,"spacing")
	DEFINE_GETTER_SETTER (RefigureMode,Boolean,"refigureMode")
	DEFINE_GETTER_SETTER (SeparatorOn,Boolean,"separatorOn")
	DEFINE_GETTER_SETTER (SashIndent,Position,"sashIndent")
	DEFINE_GETTER_SETTER (SashWidth,Dimension,"sashWidth")
	DEFINE_GETTER_SETTER (SashHeight,Dimension,"sashHeight")
	DEFINE_GETTER_SETTER (SashShadowThickness,int,"sashShadowThickness")
};

#define	NULLWXmPanedWindow		WXmPanedWindow((Widget)0)

/*
class CXmPanedWindow : public CXmManager {
public :
	DEFINE_CINIT(CXmPanedWindow, CXmManager, xmPanedWindowWidgetClass)
   DEFINE_GETTER_SETTER (AllowResize,        Boolean,        "allowResize")
   DEFINE_GETTER_SETTER (PaneMinimum,        Dimension,      "paneMinimum")
   DEFINE_GETTER_SETTER (PaneMaximum,        Dimension,      "paneMaximum")
   DEFINE_GETTER_SETTER (PositionIndex,      short,          "positionIndex")
   DEFINE_GETTER_SETTER (SkipAdjust,         Boolean,        "skipAdjust")

};
*/

#endif
