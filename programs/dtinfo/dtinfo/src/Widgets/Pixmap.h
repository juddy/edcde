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
/* $XConsortium: Pixmap.h /main/3 1996/06/11 16:45:38 cde-hal $ */
#ifndef _Pixmap_h
#define _Pixmap_h

#include <X11/StringDefs.h>

_XFUNCPROTOBEGIN

externalref WidgetClass pixmapWidgetClass;

typedef struct _PixmapClassRec * PixmapWidgetClass;
typedef struct _PixmapRec      * PixmapWidget;

#define IsPixmapWidget(w) XtIsSubclass(w, pixmapWidgetClass)

/* access to pixmap width/height */
extern void PixmapWidgetDimensions(Widget w, Dimension *width, Dimension *height);


_XFUNCPROTOEND

#endif 
/* DON'T ADD STUFF AFTER THIS #endif */
