/*
 * $XConsortium: HelpAgent.hh /main/7 1996/08/20 19:56:38 cde-hal $
 *
 * Copyright (c) 1993 HAL Computer Systems International, Ltd.
 * All rights reserved.  Unpublished -- rights reserved under
 * the Copyright Laws of the United States.  USE OF A COPYRIGHT
 * NOTICE IS PRECAUTIONARY ONLY AND DOES NOT IMPLY PUBLICATION
 * OR DISCLOSURE.
 * 
 * THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE
 * SECRETS OF HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.  USE,
 * DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE
 * PRIOR EXPRESS WRITTEN PERMISSION OF HAL COMPUTER SYSTEMS
 * INTERNATIONAL, LTD.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject
 * to the restrictions as set forth in subparagraph (c)(l)(ii)
 * of the Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013.
 *
 *          HAL COMPUTER SYSTEMS INTERNATIONAL, LTD.
 *                  1315 Dell Avenue
 *                  Campbell, CA  95008
 * 
 */



// This will eventually be a LongLived subclass...  18:22 22-Jun-93 DJB 

#ifndef wwl_h
#include <WWL/wwl.h>
#endif

class WXmPrimitive;
class WXmManager;
class WXmPushButton;
class WXmPushButtonGadget;
class WXmGadget;

class HelpAgent
{
public:
  HelpAgent();
  ~HelpAgent();

  void display_help (Widget w);
  void display_help (const String card_id);

  void add_context_help (Widget);

  void add_help_cb(Widget);

  // locator_id is the name of an X resource 
  void add_activate_help (Widget, const String locator_id = NULL);
  void add_activate_help (WXmPushButton &, const String locator_id = NULL);
  void add_activate_help (WXmPushButtonGadget &, const String locator_id = NULL);

  void activate_help (Widget,String);
  void context_help (Widget);
  void help_cb(Widget);

private:
  void create_ui();
  char *get_locator_id(const Widget w);
  Cursor create_help_cursor(Widget);

  void Popup();

private:
  Widget f_helper;
  Cursor f_cursor;
  XrmDatabase f_appXrmDb;

#if defined(__osf__)
  friend inline HelpAgent &help_agent();
#else
  friend HelpAgent &help_agent();
#endif

  static HelpAgent *g_help_agent;
};


// HelpAgent global accessor.

inline HelpAgent &
help_agent()
{
  if (HelpAgent::g_help_agent == NULL)
    HelpAgent::g_help_agent = new HelpAgent();

  return (*HelpAgent::g_help_agent);
}
