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
 *      $XConsortium: layout.c /main/3 1995/11/06 17:32:07 rswiston $
 *
 * %W% %G%      cde_app_builder/src/ab
 *
 *      RESTRICTED CONFIDENTIAL INFORMATION:
 *
 *      The information in this document is subject to special
 *      restrictions in a confidential disclosure agreement between
 *      HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *      document outside HP, IBM, Sun, USL, SCO, or Univel without
 *      Sun's specific written approval.  This document and all copies
 *      and derivative works thereof must be returned or destroyed at
 *      Sun's request.
 *
 *      Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 */


#include <stdio.h>
#include <Xm/Xm.h>
#include <Xm/BulletinB.h>
#include <Mrm/MrmAppl.h>
#include <ab_private/ab.h>

/*************************************************************************
**
**       Global  Data
**
**************************************************************************/
static const char	*layoutwin_dialog = { "ablayoutwin" };

/*************************************************************************
**
**       Function Definitions
**
**************************************************************************/

/*
 * Popup the layout window by managing the BulletinBoard child of the
 * Dialog shell.
 */
void
layout_show_dialog(
    Widget              widget,
    MrmHierarchy	s_mrm_hierarchy
)
{
    Widget	shell;
    Widget      *children;
    MrmType     class   = NULL;
 
    /* Get the dialog shell for the layout popup window.  */

    if (AB_layout_dialog == NULL)
    {
	if (MrmFetchWidget(s_mrm_hierarchy, (String)layoutwin_dialog,
                 widget, &shell, &class) != MrmSUCCESS)
	{
	    fprintf(stderr,"Can't fetch interface\n");
	    exit(1);
	}
        XtAddCallback(shell, XtNpopupCallback,
                ab_dialog_popupCB, (XtPointer)LayoutEditorUp);
        XtAddCallback(shell, XtNpopdownCallback,
                ab_dialog_popdownCB, (XtPointer)LayoutEditorUp);

	/* Now get the handle to the bulletin board widget, so that
	* we can popup the layout window by managing the BBoard.
	*/
	XtVaGetValues(shell, XmNchildren, &children, NULL);

	/* There can be only one child of a shell widget, and
	* we know that the child is the BBoard widget.
	*/
	if (*children != NULL)
	{
	    /* Store the layout dialog bulletin board handle in
	     * a global variable so that it can be easily accessed.
	     */
	    AB_layout_dialog = *children;
	}
    }
    XtManageChild(AB_layout_dialog);
}
