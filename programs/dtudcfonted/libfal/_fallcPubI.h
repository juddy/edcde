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
/* XlcPubI.h 1.1 - Fujitsu source for CDEnext    95/11/06 20:32:05 	*/ 
/* $XConsortium: _fallcPubI.h /main/1 1996/04/08 15:17:59 cde-fuj $ */
/*
 * Copyright 1992, 1993 by TOSHIBA Corp.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of TOSHIBA not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. TOSHIBA make no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * TOSHIBA DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
 * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
 * TOSHIBA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
 * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
 * Author: Katsuhisa Yano	TOSHIBA Corp.
 *			   	mopi@osa.ilab.toshiba.co.jp
 */

#ifndef _XLCPUBLICI_H_
#define _XLCPUBLICI_H_

#include "_fallcPublic.h"

#define XLC_PUBLIC(lcd, x)	(((XLCdPublic) lcd->core)->pub.x)
#define XLC_PUBLIC_PART(lcd)	(&(((XLCdPublic) lcd->core)->pub))
#define XLC_PUBLIC_METHODS(lcd)	(&(((XLCdPublicMethods) lcd->methods)->pub))

/*
 * XLCd public methods
 */

typedef struct _XLCdPublicMethodsRec *XLCdPublicMethods;

typedef XLCd (*XlcPubCreateProc)(
#if NeedFunctionPrototypes
    char*		/* name */,
    XLCdMethods		/* methods */
#endif
);

typedef Bool (*XlcPubInitializeProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

typedef void (*XlcPubDestroyProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

typedef char* (*XlcPubGetValuesProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    XlcArgList		/* args */,
    int			/* num_args */
#endif
);

typedef void (*XlcPubGetResourceProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    char*		/* category */,
    char*		/* class */,
    char***		/* value */,
    int*		/* count */
#endif
);

typedef struct _XLCdPublicMethodsPart {
    XLCdPublicMethods superclass;
    XlcPubCreateProc create;
    XlcPubInitializeProc initialize;
    XlcPubDestroyProc destroy;
    XlcPubGetValuesProc get_values;
    XlcPubGetResourceProc get_resource;
} XLCdPublicMethodsPart;

typedef struct _XLCdPublicMethodsRec {
    XLCdMethodsRec core;
    XLCdPublicMethodsPart pub;
} XLCdPublicMethodsRec;

/*
 * XLCd public data
 */

typedef struct _XLCdPublicPart {
    char *siname;			/* for _fallcMapOSLocaleName() */
    char *language;			/* language part of locale name */
    char *territory;			/* territory part of locale name */
    char *codeset;			/* codeset part of locale name */
    char *encoding_name;		/* encoding name */
    int mb_cur_max;			/* ANSI C MB_CUR_MAX */
    Bool is_state_depend;		/* state-depend encoding */
    char *default_string;		/* for falDefaultString() */
    XPointer xlocale_db;
} XLCdPublicPart;

typedef struct _XLCdPublicRec {
    XLCdCoreRec core;	
    XLCdPublicPart pub;
} XLCdPublicRec, *XLCdPublic;

extern XLCdMethods _fallcPublicMethods;

_XFUNCPROTOBEGIN

extern XLCd _fallcCreateLC(
#if NeedFunctionPrototypes
    char*		/* name */,
    XLCdMethods		/* methods */
#endif
);

extern void _fallcDestroyLC(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

extern Bool _fallcParseCharSet(
#if NeedFunctionPrototypes
    XlcCharSet		/* charset */
#endif
);

extern XlcCharSet _fallcCreateDefaultCharSet(
#if NeedFunctionPrototypes
    char*		/* name */,
    char*		/* control_sequence */
#endif
);

extern XlcCharSet _fallcAddCT(
#if NeedFunctionPrototypes
    char*		/* name */,
    char*		/* control_sequence */
#endif
);

extern XrmMethods _falrmDefaultInitParseInfo(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    XPointer*		/* state */
#endif
);

extern int _falmbTextPropertyToTextList(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* dpy */,
    XTextProperty*	/* text_prop */,
    char***		/* list_ret */,
    int*		/* count_ret */
#endif
);

extern int _falwcTextPropertyToTextList(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* dpy */,
    XTextProperty*	/* text_prop */,
    wchar_t***		/* list_ret */,
    int*		/* count_ret */
#endif
);

extern int _falmbTextListToTextProperty(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* dpy */,
    char**		/* list */,
    int			/* count */,
    XICCEncodingStyle	/* style */,
    XTextProperty*	/* text_prop */
#endif
);

extern int _falwcTextListToTextProperty(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* dpy */,
    wchar_t**		/* list */,
    int			/* count */,
    XICCEncodingStyle	/* style */,
    XTextProperty*	/* text_prop */
#endif
);

extern void _falwcFreeStringList(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    wchar_t**		/* list */
#endif
);

extern int _fallcResolveLocaleName(
#if NeedFunctionPrototypes
    char*		/* lc_name */,
    char*		/* full_name */,
    char*		/* language */,
    char*		/* territory */,
    char*		/* codeset */
#endif
);

extern int _fallcResolveDBName(
#if NeedFunctionPrototypes
    char*		/* lc_name */,
    char*		/* file_name */
#endif
);

extern int _fallcResolveI18NPath(
#if NeedFunctionPrototypes
    char*		/* path_name */
#endif
);

extern XPointer _fallcCreateLocaleDataBase(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

extern void _fallcDestroyLocaleDataBase(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

extern void _fallcGetLocaleDataBase(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    char*		/* category */,
    char*		/* name */,
    char***		/* value */,
    int*		/* count */
#endif
);

_XFUNCPROTOEND

#endif  /* _XLCPUBLICI_H_ */
