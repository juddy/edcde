/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
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
/*** DTB_USER_CODE_END   ^^^ Add file header above ^^^ ***/

/*
 * File: about_box_stubs.c
 * Contains: Module callbacks and connection functions
 *
 * This file was generated by dtcodegen, from module about_box
 *
 * Any text may be added between the DTB_USER_CODE_START and
 * DTB_USER_CODE_END comments (even non-C code). Descriptive comments
 * are provided only as an aid.
 *
 *  ** EDIT ONLY WITHIN SECTIONS MARKED WITH DTB_USER_CODE COMMENTS.  **
 *  ** ALL OTHER MODIFICATIONS WILL BE OVERWRITTEN. DO NOT MODIFY OR  **
 *  ** DELETE THE GENERATED COMMENTS!                                 **
 */

#include <stdio.h>
#include <Xm/Xm.h>
#include "dtb_utils.h"
#include "dtbuilder.h"
#include "about_box_ui.h"

/*
 * Header files for cross-module connections
 */
#include "palette_ui.h"


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All necessary header files have been included.
 ***
 *** Add include files, types, macros, externs, and user functions here.
 ***/
#include "ab.h"

static void set_by( Widget widget, char *by);

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/



void 
about_box_ok_btn_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbAboutBoxDialogInfo	instance = (DtbAboutBoxDialogInfo)clientData;
    
    if (!(instance->initialized))
    {
        dtb_about_box_dialog_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }
    XtUnmanageChild(instance->dialog_shellform);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
about_box_more_btn_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbAboutBoxDialog2Info	instance = (DtbAboutBoxDialog2Info)clientData;
    
    if (!(instance->initialized))
    {
        dtb_about_box_dialog2_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }
    XtManageChild(instance->dialog2_shellform);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
about_box_by_close_btn_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    DtbAboutBoxDialog2Info	instance = (DtbAboutBoxDialog2Info)clientData;
    
    if (!(instance->initialized))
    {
        dtb_about_box_dialog2_initialize(instance, dtb_palette_ab_palette_main.ab_palette_main);
    }
    XtUnmanageChild(instance->dialog2_shellform);
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by1_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"David Blomgren");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by2_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"David Bryant");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by3_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Patrick Curran");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by4_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Jeff Dunn");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by5_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Brian Freeman");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by6_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Monica Gaines");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by7_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Isa Hashim");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by8_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Terre Layton");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by9_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Amy Moore");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by10_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Satyajit Nath");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by11_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Andy Sobel");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
by12_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialog2Info	dtbSource = (DtbAboutBoxDialog2Info)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,"Martha Venegas");
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
os_number_createCB(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbAboutBoxDialogInfo	dtbSource = (DtbAboutBoxDialogInfo)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    set_by(widget,AbVERSION_STRING);
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}



/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All automatically-generated data and functions have been defined.
 ***
 *** Add new functions here, or at the top of the file.
 ***/

static void
set_by(
    Widget widget,
    char *by
)
{
    XmString			label;

    label = XmStringCreateLocalized(by);
    XtVaSetValues(widget,XmNlabelString,label, NULL);
    XmStringFree(label);
}

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/

