/*
 * $XConsortium: InfoBase.hh /main/3 1996/06/11 16:19:27 cde-hal $
 *
 * Copyright (c) 1992 HAL Computer Systems International, Ltd.
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

class InfobaseEntry ;

class InfoBase : public LibraryElement
{
  enum { AVERAGE_BOOKS_PER = 6 };

public: // functions
  DEF_CLASS (InfoBase);

  InfoBase (info_base *infobase)
    : f_infobase (infobase),
      f_search_info(NULL)
    { display_flag (0); }

  // NOTE: hide LEND here ! 

  const char *desc() const	{ return f_infobase->get_base_desc() ; }
  const char *path() const	{ return f_infobase->get_base_path() ; }
  const char *name() const	{ return f_infobase->get_base_name() ; }


  // NOTE: need to get rid of const casts (needs lend support?) 
  const char *display_as()
    { return ((const char *) f_infobase->get_base_desc()); }

  const char *id()
    { return ((const char *) f_infobase->get_base_name()); }

  InfobaseEntry *search_info() const 
  { return f_search_info ; }
  
  InfobaseEntry *search_info(InfobaseEntry* info);

  bool has_children_internal();

protected: // functions
  void create_children();
  void display();

protected: // variables
  info_base	*f_infobase;
  InfobaseEntry *f_search_info ; // storage freed elsewhere (SearchEngine)
};

inline InfobaseEntry *
InfoBase::search_info(InfobaseEntry * info)
{ 
    assert(f_search_info == NULL); // debugging only, no error handline reqd - jbm 
    f_search_info = info ; 
    return info; 
}

