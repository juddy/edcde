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
/* $XConsortium: dtmailopts.h /main/3 1995/11/06 16:33:51 rswiston $ */
/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
/*** DTB_USER_CODE_END   ^^^ Add file header above ^^^ ***/

/*
 * File: dtmailopts.h
 * Contains: object data structures and callback declarations
 *
 * This file was generated by dtcodegen, from project dtmailopts
 *
 * Any text may be added between the DTB_USER_CODE_START and
 * DTB_USER_CODE_END comments (even non-C code). Descriptive comments
 * are provided only as an aid.
 *
 *  ** EDIT ONLY WITHIN SECTIONS MARKED WITH DTB_USER_CODE COMMENTS.  **
 *  ** ALL OTHER MODIFICATIONS WILL BE OVERWRITTEN. DO NOT MODIFY OR  **
 *  ** DELETE THE GENERATED COMMENTS!                                 **
 */
#ifndef _DTMAILOPTS_H_
#define _DTMAILOPTS_H_

#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <nl_types.h>
#define DTB_PROJECT_CATALOG	"dtmailopts"
/* Handle for standard message catalog for the project */
extern nl_catd	Dtb_project_catd;

/*
 * Structure to store values for Application Resources
 */
typedef struct {
    char	*session_file;
    
    /*** DTB_USER_CODE_START vvv Add structure fields below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add structure fields above ^^^ ***/
} DtbAppResourceRec;


extern DtbAppResourceRec	dtb_app_resource_rec;


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** Add types, macros, and externs here
 ***/

/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/


#endif /* _DTMAILOPTS_H_ */
