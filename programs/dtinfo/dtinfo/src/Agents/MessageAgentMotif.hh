/*
 * $XConsortium: MessageAgentMotif.hh /main/7 1996/11/23 14:11:57 cde-hal $
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


class WXmMessageDialog;
class WXmTextField;

class MessageAgent : public Agent
{
public: // functions
  // Initializing
  MessageAgent();

  // Displaying
  void displayError       (char *message_text, Widget parent);
  void displayWarning     (char *message_text, Widget parent);
  void displayInformation (char *message_text, Widget parent);
  void displayQuit        (char *message_text, Widget parent);
  void displayProgress	  (char *message_text, Widget parent);
  void undisplayProgress  ();
  bool displayQuestion    (char *message_text, Widget parent);

  int get_integer (const char* msg, const char* title, int default_value, Widget parent);
  const char *get_string (const char* msg, const char* title, const char* default_value, Widget parent);

  void setMaxLength(int, Widget parent);
  STATIC_SENDER_HH(CancelOperation);

private: // functions
  void create_ui          (Widget parent);
  void ok_activate        (WCallback *wcb);
  void position_dialog    (WCallback *wcb);
  void cancelOperation	  (WCallback *wcb);
  void displayMessage     (char *message_text);
  void display_it();
  void pop_down();
  void focus (WCallback *);

  void verify_integer (WCallback *wcb);
  void value_changed (WCallback *wcb);

private: // variables

  WXmMessageDialog *f_dialog;
  WXmTextField     *f_text;
  Boolean           f_exit_flag;
  Widget            f_real_parent;
  Boolean	    f_popped_up;
  Boolean           f_pressed_ok;
};

// inline:

inline
MessageAgent::MessageAgent()
: f_dialog (NULL),
  f_exit_flag (False)
{
}
