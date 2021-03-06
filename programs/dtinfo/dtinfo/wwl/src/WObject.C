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
 * $XConsortium: WObject.cc /main/3 1996/06/11 17:03:32 cde-hal $
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

// This is only for the doc
#ifdef DOC

/*?class WObject
Every widget inherits from the class \typ{WObject}.
?*/

/*?
The basic cast constructor for C++ widgets.
?*/
WObject :: WObject (Widget w)
{
	widget = w;
}

/*?
The copy constructor for C++ widgets.
?*/
WObject :: WObject (WObject& w)
{
	widget = w.widget;
}

/*?
The basic constructor for C++ widgets. Used by every subclasses.
?*/
WObject :: WObject (WComposite& super,  WidgetClass c, const char* name, ArgList args, Cardinal card)
{
	widget = XtCreateWidget (name, c, super.widget, args, card);
}

/*?
The cast operator, to get a C widget from a C++ widget.
?*/
WObject ::  operator Widget () const
{
	return widget;
}

/*?
Return the class of the widget.
?*/
WidgetClass
WObject :: WidgetClass Class () const
{
	return XtClass (widget);
}

/*?
The \fun{XtRealize} function.
?*/
void
WObject :: Realize () const
{
	XtRealizeWidget (widget);
}

/*?
The \fun{XtUnrealizeWidget} function.
?*/
void
WObject :: Unrealize () const
{
	XtUnrealizeWidget (widget);
}

/*?
The \fun{XtIsRealized} function.
?*/
Boolean
WObject :: IsRealized () const
{
	return XtIsRealized (widget);
}

/*?
The \fun{XtDestroyWidget} function.
{\em Beware to delete the C++ object after calling this method}.
?*/
void
WObject :: Destroy () const
{
	XtDestroyWidget (widget);
}

/*?
Get one resource value. Equivalent of \fun{XtGetValues} with one
\typ{XtArg} record.
?*/
Arg&
WObject :: Get (Arg& a) const
{
	XtGetValues (widget, &a, 1);
	return a;
}

/*?nodoc?*/
Arg&
WObject :: _Get (Arg& a) const
{
	XtGetValues (widget, &a, 1);
	return a;
}

/*?nextdoc?*/
void
WObject :: Get (ArgList a, Cardinal c) const
{
	XtGetValues (widget, a, c);
}

/*?
The \fun{XtGetValues} function.
?*/
void
WObject :: Get (WArgList& w) const
{
}

/*?
Set one resource value. Equivalent of \fun{XtSetValues} with one
\typ{XtArg} record.
?*/
Arg&
WObject :: Set (Arg& a) const
{
	XtSetValues (widget, &a, 1);
	return a;
}

/*?nodoc?*/
Arg&
WObject :: _Set (Arg& a) const
{
	XtSetValues (widget, &a, 1);
	return a;
}

/*?nextdoc?*/
void
WObject :: Set (ArgList a, Cardinal c) const
{ 
	XtSetValues (widget, a, c);
}

/*?
The \fun{XtSetValues} function.
?*/
void
WObject :: Set (WArgList& w) const
{ 
}

/*?
The \fun{XtAddCallback} function.
?*/
void
WObject :: AddCallback (const char* name, XtCallbackProc proc, caddr_t closure) const
{
	XtAddCallback (widget, name, proc, closure);
}

/*?
The \fun{XtRemoveCallback} function.
?*/
void
WObject :: RemoveCallback (const char* name, XtCallbackProc proc, caddr_t closure) const
{
	XtRemoveCallback (widget, name, proc, closure);
}

/*?
The \fun{XtAddCallbacks} function.
?*/
void
WObject :: AddCallbacks (const char* name, XtCallbackList callbacks) const
{
	XtAddCallbacks (widget, name, callbacks);
}

/*?
The \fun{XtRemoveCallbacks} function.
?*/
void
WObject :: RemoveCallbacks (const char* name, XtCallbackList callbacks) const
{
	XtRemoveCallbacks (widget, name, callbacks);
}

/*?
The \fun{XtRemoveAllCallbacks} function.
?*/
void
WObject :: RemoveAllCallbacks (const char* name) const
{
	XtRemoveAllCallbacks (widget, name);
}

/*?
The \fun{XtCallCallbacks} function.
?*/
void
WObject :: CallCallbacks (const char* name, caddr_t call_data) const
{
	XtCallCallbacks (widget, name, call_data);
}

/*?nodoc?*/
WCallback*
WObject :: SetCallback (const char* name, WWL* obj, WWL_FUN fun)
{
	return new WCallback (*this, name, obj, fun);
}
#else // Not for doc

#include <WWL/WComposite.h>
#include <sstream>
using namespace std;

#define NL << '\n'; cout.flush()

WObject :: WObject (const WComposite& super,  WidgetClass c, const char* name,
		    ArgList args, Cardinal card)
{
//   cout << "Creating widget " << name << " with " << card << " args." NL;
   widget = XtCreateWidget (name, c, super.widget, args, card);
}

WObject :: WObject (const WComposite& super, int automanage, WidgetClass c,
                    const char* name, ArgList args, Cardinal card)
{
   automanage = 1;
   widget = XtCreateManagedWidget (name, c, super.widget, args, card);
}

WObject :: WObject (const WComposite& super,  Boolean popup,  WidgetClass c,
		    const char* name, ArgList args, Cardinal card)
{
   if (popup)
      widget = XtCreatePopupShell(name, c, super.widget, args, card);
   else
      widget = XtCreateWidget (name, c, super.widget, args, card);
}

#endif
