/*
 * $XConsortium: UserPreference.hh /main/3 1996/06/11 16:44:56 cde-hal $
 *
 * Copyright (c) 1992 HaL Computer Systems, Inc.  All rights reserved.
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

class PreferenceRecord
{
public:
  PreferenceRecord (const char *key, const char *value);
  ~PreferenceRecord();

  void set_value (const char *value);

  static PreferenceRecord *lookup (const char *key);
  static const char *form_filename();
  static void read_prefs();

  const char *f_key;
  const char *f_value;

private:
  PreferenceRecord *f_next;

  static PreferenceRecord *g_head;
  static PreferenceRecord *g_tail;
  static int g_update_count;
};


class UserPreference
{
public:
  UserPreference (const char *key);
  virtual ~UserPreference();

protected:
  const char *key()
    { return (f_preference->f_key); }
  const char *value()
    { return (f_preference->f_value); }
  void set_value (const char *value)
    { f_preference->set_value (value); }

protected:
  char g_buffer[256];

private:
  PreferenceRecord *f_preference;
};
