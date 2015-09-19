/* $TOG: CheckBoxUiItem.hh /main/5 1997/11/07 15:44:05 mgreess $ */
/*
 *+SNOTICE
 *
 *	RESTRICTED CONFIDENTIAL INFORMATION:
 *	
 *	The information in this document is subject to special
 *	restrictions in a confidential disclosure agreement bertween
 *	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *	document outside HP, IBM, Sun, USL, SCO, or Univel wihtout
 *	Sun's specific written approval.  This documment and all copies
 *	and derivative works thereof must be returned or destroyed at
 *	Sun's request.
 *
 *	Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 *+ENOTICE
 */

#ifndef _CHECKBOXUIITEM_HH
#define _CHECKBOXUIITEM_HH

#include <stdlib.h>
#include <X11/Intrinsic.h>

#include <DtMail/PropUi.hh>

// CLASS CheckBoxUiItem
// derived class for prop sheet glue items for CheckBox
///////////////////////////////////////////////////////////
class CheckBoxUiItem : public PropUiItem {
  
public:
  CheckBoxUiItem(Widget w, int source, char *search_key);
  virtual ~CheckBoxUiItem(){;}; // we don't alloc any memory
#ifdef DEAD_WOOD
  virtual int getType(){ return _CHECKBOX_ITEM; };
  virtual int getSource(){ return data_source; };
#endif /* DEAD_WOOD */
  virtual void writeFromUiToSource();
  virtual void writeFromSourceToUi();

private:
#ifdef DEAD_WOOD
  int data_source;
#endif /* DEAD_WOOD */
};

#endif
