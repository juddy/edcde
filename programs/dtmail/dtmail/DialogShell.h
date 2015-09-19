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
 *+SNOTICE
 *
 *	$TOG: DialogShell.h /main/5 1998/01/28 18:35:07 mgreess $
 *
 *	RESTRICTED CONFIDENTIAL INFORMATION:
 *	
 *	The information in this document is subject to special
 *	restrictions in a confidential disclosure agreement between
 *	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *	document outside HP, IBM, Sun, USL, SCO, or Univel without
 *	Sun's specific written approval.  This document and all copies
 *	and derivative works thereof must be returned or destroyed at
 *	Sun's request.
 *
 *	Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 *+ENOTICE
 */

#ifndef DIALOGSHELL_H
#define DIALOGSHELL_H

#include <Xm/DialogS.h>
#include "UIComponent.h"

class RoamMenuWindow;

class DialogShell : public UIComponent {

  public:
    DialogShell(
		char		*name,
		RoamMenuWindow	*parent,
		WidgetClass	wc = xmDialogShellWidgetClass);
    virtual ~DialogShell();
    virtual void initialize();
    
// Accessors
    
    RoamMenuWindow *parent() { return _parent; };
    Widget work_area(){ return _workArea; }
    
// Mutators
    
    virtual void title( char * );
    virtual void popped_up()=0;
    virtual void popped_down()=0;
    virtual void manage();
    virtual void busyCursor();
    virtual void normalCursor();
    
    virtual void quit()=0;
    
  protected:

    virtual Widget createWorkArea( Widget ) = 0;
    static void popdownCallback ( Widget, XtPointer, XmAnyCallbackStruct * );
    static void popupCallback( Widget, XtPointer, XmAnyCallbackStruct * );
    Widget _workArea;

  private:

    static void quitCallback( Widget, XtPointer, XmAnyCallbackStruct * );    

    RoamMenuWindow *_parent;
    WidgetClass	_widgetClass;

};

#endif
