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
/*%%  (c) Copyright 1993, 1994 Hewlett-Packard Company			 */
/*%%  (c) Copyright 1993, 1994 International Business Machines Corp.	 */
/*%%  (c) Copyright 1993, 1994 Sun Microsystems, Inc.			 */
/*%%  (c) Copyright 1993, 1994 Novell, Inc. 				 */
/*%%  $XConsortium: eclipse.h /main/3 1995/10/23 10:31:27 rswiston $ 			 				 */
/*
 * @(#)eclipse.h	1.3 93/09/07
 */
#ifndef ttdtprocid_h
#define ttdtprocid_h

#include "ticccm.h"

//
// An instance of this class will install the given procID as
// the new default procID, and will restore the old default
// procID when it goes out of scope.
//
class TtDtProcIDEclipse {
    public:
			TtDtProcIDEclipse(
				const char *procID2Install,
				Tt_status  *status
			);
			~TtDtProcIDEclipse();
    private:
	const char     *_occultedProcID;
};

#endif
