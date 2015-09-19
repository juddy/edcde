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
/* Xlcint.h 1.4 - Fujitsu source for CDEnext    95/12/07 10:53:09 	*/ 
/* $XConsortium: _fallcint.h /main/1 1996/04/08 15:20:05 cde-fuj $ */
/*

Copyright (c) 1991  X Consortium

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from the X Consortium.

*/

/*
 * Copyright 1990, 1991 by OMRON Corporation, NTT Software Corporation,
 *                      and Nippon Telegraph and Telephone Corporation
 * Copyright 1991 by the Open Software Foundation
 * Copyright 1993 by the TOSHIBA Corp.
 * Copyright 1993, 1994 by Sony Corporation
 * Copyright 1993, 1994 by the FUJITSU LIMITED
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of OMRON, NTT Software, NTT, Open
 * Software Foundation, and Sony Corporation not be used in advertising
 * or publicity pertaining to distribution of the software without specific, 
 * written prior permission. OMRON, NTT Software, NTT, Open Software
 * Foundation, and Sony Corporation  make no representations about the 
 * suitability of this software for any purpose.  It is provided "as is" 
 * without express or implied warranty.
 *
 * OMRON, NTT SOFTWARE, NTT, OPEN SOFTWARE FOUNDATION, AND SONY 
 * CORPORATION DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING 
 * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT 
 * SHALL OMRON, NTT SOFTWARE, NTT, OPEN SOFTWARE FOUNDATION, OR SONY 
 * CORPORATION BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
 * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT 
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 *	Authors: Li Yuhong		OMRON Corporation
 *		 Tatsuya Kato		NTT Software Corporation
 *		 Hiroshi Kuribayashi	OMRON Coproration
 *		 Muneiyoshi Suzuki	Nippon Telegraph and Telephone Co.
 * 
 *		 M. Collins		OSF  
 *		 Katsuhisa Yano		TOSHIBA Corp.
 *               Makoto Wakamatsu       Sony Corporation
 *               Takashi Fujiwara	FUJITSU LIMITED
 */				
/*
 *  (c) Copyright 1995 FUJITSU LIMITED
 *  This is source code modified by FUJITSU LIMITED under the Joint
 *  Development Agreement for the CDEnext PST.
 *  This is unpublished proprietary source code of FUJITSU LIMITED
 */


#ifndef	_XLCINT_H_
#define	_XLCINT_H_

#include <X11/Xresource.h>
#include "_falutil.h"
#include "_falvarargs.h"

typedef Bool (*XFilterEventProc)(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Window		/* window */,
    XEvent*		/* event */,
    XPointer		/* client_data */
#endif
);

typedef struct _XIMFilter {
    struct _XIMFilter *next;
    Window window;
    unsigned long event_mask;
    int start_type, end_type;
    XFilterEventProc filter;
    XPointer client_data;
} XFilterEventRec, *XFilterEventList;

typedef struct {
    char    *name;
    XPointer value;
} XIMArg;

#ifdef offsetof
#define XOffsetOf(s_type,field) offsetof(s_type,field)
#else
#define XOffsetOf(s_type,field) ((unsigned int)&(((s_type*)NULL)->field))
#endif

#define XIMNumber(arr) ((unsigned int) (sizeof(arr) / sizeof(arr[0])))

/*
 * define secondary data structs which are part of Input Methods
 * and Input Context
 */
typedef struct {
    char		*resource_name;		/* Resource string */
    XrmQuark		xrm_name;		/* Resource name quark */
    int			resource_size;		/* Size in bytes of data */
    long		resource_offset;	/* Offset from base */
    unsigned short 	mode;			/* Read Write Permission */
    unsigned short 	id;			/* Input Method Protocol */
} XIMResource, *XIMResourceList;

/*
 * data block describing the visual attributes associated with
 * an input context
 */
typedef struct {
    XRectangle		area;
    XRectangle		area_needed;
    XPoint		spot_location;
    Colormap		colormap;
    Atom		std_colormap;
    unsigned long	foreground;
    unsigned long	background;
    Pixmap		background_pixmap;
    XFontSet            fontset;
    int	       		line_spacing;
    Cursor		cursor;
    XIMCallback		start_callback;
    XIMCallback		done_callback;
    XIMCallback		draw_callback;
    XIMCallback		caret_callback;
    XIMPreeditState	preedit_state;
    XIMCallback		state_notify_callback;
} ICPreeditAttributes, *ICPreeditAttributesPtr;

typedef struct {
    XRectangle		area;
    XRectangle		area_needed;
    Colormap		colormap;
    Atom		std_colormap;
    unsigned long	foreground;
    unsigned long	background;
    Pixmap		background_pixmap;
    XFontSet            fontset;
    int	       		line_spacing;
    Cursor		cursor;
    XIMCallback		start_callback;
    XIMCallback		done_callback;
    XIMCallback		draw_callback;
} ICStatusAttributes, *ICStatusAttributesPtr;

/*
 * Methods for Xrm parsing
 */

typedef void (*XmbInitProc)(
#if NeedFunctionPrototypes
    XPointer		/* state */
#endif
);

typedef char (*XmbCharProc)(
#if NeedFunctionPrototypes
    XPointer		/* state */,
    char*		/* str */,
    int*		/* lenp */
#endif
);

typedef void (*XmbFinishProc)(
#if NeedFunctionPrototypes
    XPointer		/* state */
#endif
);

typedef char* (*XlcNameProc)(
#if NeedFunctionPrototypes
    XPointer		/* state */
#endif
);

typedef void (*XrmDestroyProc)(
#if NeedFunctionPrototypes
    XPointer		/* state */
#endif
);

typedef struct {
    XmbInitProc		mbinit;
    XmbCharProc		mbchar;
    XmbFinishProc	mbfinish;
    XlcNameProc		lcname;
    XrmDestroyProc	destroy;
} XrmMethodsRec, *XrmMethods;

typedef struct _XLCd *XLCd; /* need forward reference */

/*
 * define an LC, it's methods, and data.
 */

typedef void (*XCloseLCProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

typedef char* (*XlcMapModifiersProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    char*		/* user_mods */,
    char*		/* prog_mods */
#endif
);

typedef XOM (*XOpenOMProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    XrmDatabase		/* rdb */,
    _Xconst char*	/* res_name */,
    _Xconst char*	/* res_class */
#endif
);

typedef XIM (*XOpenIMProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    XrmDatabase		/* rdb */,
    char*		/* res_name */,
    char*		/* res_class */
#endif
);

typedef Bool (*XRegisterIMInstantiateCBProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    XrmDatabase		/* rdb */,
    char*		/* res_name */,
    char*		/* res_class */,
    XIMProc		/* callback */,
    XPointer*		/* client_data */
#endif
);

typedef Bool (*XUnregisterIMInstantiateCBProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    XrmDatabase		/* rdb */,
    char*		/* res_name */,
    char*		/* res_class */,
    XIMProc		/* callback */,
    XPointer*		/* client_data */
#endif
);

typedef XrmMethods (*XrmInitParseInfoProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    XPointer*		/* state */
#endif
);

typedef int (*falmbTextPropertyToTextListProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    XTextProperty*	/* text_prop */,
    char***		/* list_return */,
    int*		/* count_return */
#endif
);

typedef int (*falwcTextPropertyToTextListProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    XTextProperty*	/* text_prop */,
    wchar_t***		/* list_return */,
    int*		/* count_return */
#endif
);

typedef int (*falmbTextListToTextPropertyProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    char**		/* list */,
    int			/* count */,
    XICCEncodingStyle	/* style */,
    XTextProperty*	/* text_prop_return */
#endif
);

typedef int (*falwcTextListToTextPropertyProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* display */,
    wchar_t**		/* list */,
    int			/* count */,
    XICCEncodingStyle	/* style */,
    XTextProperty*	/* text_prop_return */
#endif
);

typedef void (*falwcFreeStringListProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    wchar_t**		/* list */
#endif
);

typedef char* (*falDefaultStringProc)(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

typedef struct {
    XCloseLCProc			close;
    XlcMapModifiersProc			map_modifiers;
    XOpenOMProc				open_om;
    XOpenIMProc				open_im;
    XrmInitParseInfoProc		init_parse_info;
    falmbTextPropertyToTextListProc	mb_text_prop_to_list;
    falwcTextPropertyToTextListProc	wc_text_prop_to_list;
    falmbTextListToTextPropertyProc	mb_text_list_to_prop;
    falwcTextListToTextPropertyProc	wc_text_list_to_prop;
    falwcFreeStringListProc		wc_free_string_list;
    falDefaultStringProc			default_string;
    XRegisterIMInstantiateCBProc	register_callback;
    XUnregisterIMInstantiateCBProc	unregister_callback;
} XLCdMethodsRec, *XLCdMethods;


typedef struct {
    char*		name;			/* name of this LC */
    char*		modifiers;		/* modifiers of locale */
} XLCdCoreRec, *XLCdCore;


typedef struct _XLCd {
    XLCdMethods		methods;		/* methods of this LC */
    XLCdCore		core;			/* data of this LC */
    XPointer		opaque;			/* LDX specific data */
} XLCdRec;

typedef int XlcPosition;

#define XlcHead		0
#define XlcTail		-1

typedef struct {
    char *name;
    XPointer value;
} XlcArg, *XlcArgList;

typedef struct _XlcResource {
    char *name;
    XrmQuark xrm_name;
    int size;
    int offset;
    unsigned long mask;
} XlcResource, *XlcResourceList;

#define XlcCreateMask	(1L<<0)
#define XlcDefaultMask	(1L<<1)
#define XlcGetMask	(1L<<2)
#define XlcSetMask	(1L<<3)
#define XlcIgnoreMask	(1L<<4)

#define XlcNumber(arr)	(sizeof(arr) / sizeof(arr[0]))

typedef Status (*XCloseOMProc)(
#if NeedFunctionPrototypes
    XOM			/* om */
#endif
);

typedef char* (*XSetOMValuesProc)(
#if NeedFunctionPrototypes
    XOM			/* om */,
    XlcArgList		/* args */,
    int			/* num_args */
#endif
);

typedef char* (*XGetOMValuesProc)(
#if NeedFunctionPrototypes
    XOM			/* om */,
    XlcArgList		/* args */,
    int			/* num_args */
#endif
);

typedef XOC (*XCreateOCProc)(
#if NeedFunctionPrototypes
    XOM			/* om */,
    XlcArgList		/* args */,
    int			/* num_args */
#endif
);

typedef struct _XOMMethodsRec {
    XCloseOMProc	close;
    XSetOMValuesProc	set_values;
    XGetOMValuesProc	get_values;
    XCreateOCProc	create_oc;
} XOMMethodsRec, *XOMMethods;

typedef struct _XOMCoreRec {
    XLCd lcd;				/* lcd */
    Display *display;			/* display */
    XrmDatabase rdb;			/* database */
    char *res_name;			/* resource name */
    char *res_class;			/* resource class */
    XOC oc_list;			/* xoc list */
    XlcResourceList resources;		/* xom resources */
    int num_resources;			/* number of xom resources */
    XOMCharSetList required_charset;	/* required charset list */
    XOMOrientation orientation_list;	/* orientation list */
    Bool directional_dependent;		/* directional-dependent */
    Bool contextual_drawing;		/* contextual drawing */
    Bool context_dependent;		/* context-dependent drawing */
} XOMCoreRec, *XOMCore;

typedef struct _XOM {
    XOMMethods methods;
    XOMCoreRec core;
} XOMRec;

typedef void (*XDestroyOCProc)(
#if NeedFunctionPrototypes
    XOC			/* oc */
#endif
);

typedef char* (*XSetOCValuesProc)(
#if NeedFunctionPrototypes
    XOC			/* oc */,
    XlcArgList		/* args */,
    int			/* num_args */
#endif
);

typedef char* (*XGetOCValuesProc)(
#if NeedFunctionPrototypes
    XOC			/* oc */,
    XlcArgList		/* args */,
    int			/* num_args */
#endif
);

/*
 * X Font Sets are an instantiable object, so we define it, the 
 * object itself, a method list and data
 */

/* 
 * XFontSet object method list
 */

typedef int (*XmbTextEscapementProc)(
#if NeedFunctionPrototypes
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* text_len */
#endif
);

typedef int (*XmbTextExtentsProc)(
#if NeedFunctionPrototypes
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* text_len */,
    XRectangle*		/* overall_ink_extents */,
    XRectangle*		/* overall_logical_extents */
#endif
);

typedef Status (*XmbTextPerCharExtentsProc)(
#if NeedFunctionPrototypes
    XFontSet		/* font_set */,
    _Xconst char*	/* text */,
    int			/* text_len */,
    XRectangle*		/* ink_extents_buffer */,
    XRectangle*		/* logical_extents_buffer */,
    int			/* buffer_size */,
    int*		/* num_chars */,
    XRectangle*		/* max_ink_extents */,
    XRectangle*		/* max_logical_extents */
#endif
);

typedef int (*XmbDrawStringProc)(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Drawable		/* drawable */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* text */,
    int			/* text_len */
#endif
);

typedef void (*XmbDrawImageStringProc)(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Drawable		/* drawable */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst char*	/* text */,
    int			/* text_len */
#endif
);

typedef int (*XwcTextEscapementProc)(
#if NeedFunctionPrototypes
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* text_len */
#endif
);

typedef int (*XwcTextExtentsProc)(
#if NeedFunctionPrototypes
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* text_len */,
    XRectangle*		/* overall_ink_extents */,
    XRectangle*		/* overall_logical_extents */
#endif
);

typedef Status (*XwcTextPerCharExtentsProc)(
#if NeedFunctionPrototypes
    XFontSet		/* font_set */,
    _Xconst wchar_t*	/* text */,
    int			/* text_len */,
    XRectangle*		/* ink_extents_buffer */,
    XRectangle*		/* logical_extents_buffer */,
    int			/* buffer_size */,
    int*		/* num_chars */,
    XRectangle*		/* max_ink_extents */,
    XRectangle*		/* max_logical_extents */
#endif
);

typedef int (*XwcDrawStringProc)(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Drawable		/* drawable */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst wchar_t*	/* text */,
    int			/* text_len */
#endif
);

typedef void (*XwcDrawImageStringProc)(
#if NeedFunctionPrototypes
    Display*		/* display */,
    Drawable		/* drawable */,
    XFontSet		/* font_set */,
    GC			/* gc */,
    int			/* x */,
    int			/* y */,
    _Xconst wchar_t*	/* text */,
    int			/* text_len */
#endif
);

typedef struct {
    XDestroyOCProc 		destroy;
    XSetOCValuesProc 		set_values;
    XGetOCValuesProc 		get_values;

    /* multi-byte text drawing methods */

    XmbTextEscapementProc	mb_escapement;
    XmbTextExtentsProc		mb_extents;
    XmbTextPerCharExtentsProc	mb_extents_per_char;
    XmbDrawStringProc		mb_draw_string;
    XmbDrawImageStringProc	mb_draw_image_string;

    /* wide character text drawing methods */

    XwcTextEscapementProc	wc_escapement;
    XwcTextExtentsProc		wc_extents;
    XwcTextPerCharExtentsProc	wc_extents_per_char;
    XwcDrawStringProc		wc_draw_string;
    XwcDrawImageStringProc	wc_draw_image_string;
} XOCMethodsRec, *XOCMethods;


/*
 * XOC independent data
 */

typedef struct {
    XOM om;				/* XOM */
    XOC next;				/* next XOC */
    XlcResourceList resources;		/* xoc resources */
    int num_resources;			/* number of xoc resources */
    char *base_name_list;     		/* base font name list */
    Bool om_automatic;			/* OM Automatic */
    XOMFontInfo font_info;		/* font info */
    XFontSetExtents font_set_extents;  	/* font set extents */
    char *default_string;     		/* default string */
    XOMCharSetList missing_list;	/* missing charset list */
    XOrientation orientation;		/* orientation */
    char *res_name;			/* resource name */
    char *res_class;			/* resource class */
} XOCCoreRec, *XOCCore;

typedef struct _XOC {
    XOCMethods methods;
    XOCCoreRec core;
} XOCRec;


/* current Ultrix compiler gets horribly confused */
#if defined(FUNCPROTO) && defined(ultrix)
#undef NeedFunctionPrototypes
#endif


/*
 * X Input Managers are an instantiable object, so we define it, the 
 * object itself, a method list and data.
 */

/*
 * an Input Manager object method list
 */
typedef struct {
    Status (*close)(
#if NeedFunctionPrototypes
	XIM
#endif
	);
    char* (*set_values)(
#if NeedFunctionPrototypes
	XIM, XIMArg*
#endif
	);
    char* (*get_values)(
#if NeedFunctionPrototypes
	XIM, XIMArg*
#endif
	);
    XIC (*create_ic)(
#if NeedFunctionPrototypes
	XIM, XIMArg*
#endif
	);
    int (*ctstombs)(
#if NeedFunctionPrototypes
	XIM, char*, int, char*, int, Status *
#endif
	);
    int (*ctstowcs)(
#if NeedFunctionPrototypes
	XIM, char*, int, wchar_t*, int, Status *
#endif
	);
} XIMMethodsRec, *XIMMethods;

/*
 * Input Manager LC independent data
 */
typedef struct {
    XLCd		lcd;			/* LC of this input method */
    XIC			ic_chain;		/* list of ICs for this IM */

    Display *		display;               	/* display */
    XrmDatabase 	rdb;
    char *		res_name;
    char *		res_class;

    XIMValuesList	*im_values_list;
    XIMValuesList	*ic_values_list;
    XIMStyles		*styles;
    XIMCallback		 destroy_callback;
    char *		im_name;		/* XIMMODIFIER name */
    XIMResourceList	im_resources;		/* compiled IM resource list */
    unsigned int	im_num_resources;
    XIMResourceList	ic_resources;		/* compiled IC resource list */
    unsigned int	ic_num_resources;
    Bool		visible_position;
} XIMCoreRec, *XIMCore;



/*
 * An X Input Manager (IM).  Implementations may need to extend this data 
 * structure to accomodate additional data, state information etc.
 */
typedef struct _XIM {
    XIMMethods		methods;		/* method list of this IM */
    XIMCoreRec		core;			/* data of this IM */
} XIMRec;



/*
 * X Input Contexts (IC) are an instantiable object, so we define it, the 
 * object itself, a method list and data for this object
 */

/*
 * Input Context method list
 */ 
typedef struct {
    void (*destroy)(
#if NeedFunctionPrototypes
	XIC
#endif
	);
    void (*set_focus)(
#if NeedFunctionPrototypes
	XIC
#endif
	);
    void (*unset_focus)(
#if NeedFunctionPrototypes
	XIC
#endif
	);
    char* (*set_values)(
#if NeedFunctionPrototypes
	XIC, XIMArg*
#endif
	);
    char* (*get_values)(
#if NeedFunctionPrototypes
	XIC, XIMArg*
#endif
	);
    char* (*mb_reset)(
#if NeedFunctionPrototypes
	XIC
#endif
	);
    wchar_t* (*wc_reset)(
#if NeedFunctionPrototypes
	XIC
#endif
	);
    int (*mb_lookup_string)(
#if NeedFunctionPrototypes
	XIC, XKeyEvent*, char*, int, KeySym*, Status*
#endif
	);
    int (*wc_lookup_string)(
#if NeedFunctionPrototypes
	XIC, XKeyEvent*, wchar_t*, int, KeySym*, Status*
#endif
	);
} XICMethodsRec, *XICMethods;


/*
 * Input Context LC independent data
 */
typedef struct {
    XIM			im;			/* XIM this IC belongs too */
    XIC			next;			/* linked list of ICs for IM */

    Window		client_window;		/* window IM can use for */
						/* display or subwindows */
    XIMStyle		input_style;		/* IM's input style */
    Window		focus_window;		/* where key events go */
    unsigned long	filter_events;		/* event mask from IM */
    XIMCallback		geometry_callback;	/* client callback */
    char *		res_name;
    char *		res_class;

    XIMCallback		destroy_callback;
    XIMCallback		string_conversion_callback;
    XIMStringConversionText	 string_conversion;
    XIMResetState	reset_state;
    XIMHotKeyTriggers  *hotkey;
    XIMHotKeyState	hotkey_state;

    ICPreeditAttributes	preedit_attr;		/* visuals of preedit area */
    ICStatusAttributes	status_attr;		/* visuals of status area */
} XICCoreRec, *XICCore;


/*
 * an Input Context.  Implementations may need to extend this data 
 * structure to accomodate additional data, state information etc.
 */
typedef struct _XIC {
    XICMethods		methods;		/* method list of this IC */
    XICCoreRec		core;			/* data of this IC */
} XICRec;

/* current Ultrix compiler gets horribly confused */
#if !defined(NeedFunctionPrototypes) && defined(FUNCPROTO)
#define NeedFunctionPrototypes 1
#endif

typedef XLCd (*XLCdLoadProc)(
#if NeedFunctionPrototypes
    char*
#endif
);

_XFUNCPROTOBEGIN

extern XLCd _falOpenLC(
#if NeedFunctionPrototypes
    char*		/* name */
#endif
);

extern void _falCloseLC(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

extern XLCd _fallcCurrentLC(
#if NeedFunctionPrototypes
    void
#endif
);

extern Bool _fallcValidModSyntax(
#if NeedFunctionPrototypes
    char*	/* mods */,
    char**	/* valid */
#endif
);

extern char *_fallcDefaultMapModifiers(
#if NeedFunctionPrototypes
    XLCd	/* lcd */,
    char*	/* user_mods */,
    char*	/* prog_mods */
#endif
);

extern void _XIMCompileResourceList(
#if NeedFunctionPrototypes
    XIMResourceList	/* res */,
    unsigned int	/* num_res */
#endif
);

extern void _XCopyToArg(
#if NeedFunctionPrototypes
    XPointer		/* src */,
    XPointer*		/* dst */,
    unsigned int	/* size */
#endif
);

extern char ** _falParseBaseFontNameList(
#if NeedFunctionPrototypes
    char*		/* str */,
    int*		/* num */
#endif
);

extern XrmMethods _falrmInitParseInfo(
#if NeedFunctionPrototypes
	XPointer*	/* statep */
#endif
);

extern void _XRegisterFilterByMask(
#if NeedFunctionPrototypes
    Display*		/* dpy */,
    Window		/* window */,
    unsigned long	/* event_mask */,
    Bool (*)(
#if NeedNestedPrototypes
	     Display*	/* display */,
	     Window	/* window */,
	     XEvent*	/* event */,
	     XPointer	/* client_data */
#endif
	     )		/* filter */,
    XPointer		/* client_data */
#endif
);

extern void _XRegisterFilterByType(
#if NeedFunctionPrototypes
    Display*		/* dpy */,
    Window		/* window */,
    int			/* start_type */,
    int			/* end_type */,
    Bool (*)(
#if NeedNestedPrototypes
	     Display*	/* display */,
	     Window	/* window */,
	     XEvent*	/* event */,
	     XPointer	/* client_data */
#endif
	     )		/* filter */,
    XPointer		/* client_data */
#endif
);

extern void _XUnregisterFilter(
#if NeedFunctionPrototypes
    Display*		/* dpy */,
    Window		/* window */,
    Bool (*)(
#if NeedNestedPrototypes
	     Display*	/* display */,
	     Window	/* window */,
	     XEvent*	/* event */,
	     XPointer	/* client_data */
#endif
	     )		/* filter */,
    XPointer		/* client_data */
#endif
);

extern void _fallcCountVaList(
#if NeedFunctionPrototypes
    va_list		/* var */,
    int*		/* count_return */
#endif
);

extern void _fallcVaToArgList(
#if NeedFunctionPrototypes
    va_list		/* var */,
    int			/* count */,
    XlcArgList*		/* args_return */
#endif
);

extern void _fallcCompileResourceList(
#if NeedFunctionPrototypes
    XlcResourceList	/* resources */,
    int			/* num_resources */
#endif
);

extern char *_fallcGetValues(
#if NeedFunctionPrototypes
    XPointer		/* base */,
    XlcResourceList	/* resources */,
    int			/* num_resources */,
    XlcArgList		/* args */,
    int			/* num_args */,
    unsigned long	/* mask */
#endif
);

extern char *_fallcSetValues(
#if NeedFunctionPrototypes
    XPointer		/* base */,
    XlcResourceList	/* resources */,
    int			/* num_resources */,
    XlcArgList		/* args */,
    int			/* num_args */,
    unsigned long	/* mask */
#endif
);

extern Bool _fallcAddLoader(
#if NeedFunctionPrototypes
    XLCdLoadProc	/* proc */,
    XlcPosition		/* position */
#endif
);

extern void _fallcRemoveLoader(
#if NeedFunctionPrototypes
    XLCdLoadProc	/* proc */
#endif
);

_XFUNCPROTOEND

#endif	/* _XLCINT_H_ */
