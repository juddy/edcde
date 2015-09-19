/*
 * $XConsortium: MarkBase_mmdb.hh /main/3 1996/06/11 16:29:25 cde-hal $
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

#include "UAS.hh"


class mark_base;
class Mark_mmdb;

class MarkBase_mmdb : public MarkBase
{
public:
  MarkBase_mmdb (mark_base *base, bool read_only);
  ~MarkBase_mmdb();

  UAS_Pointer<Mark> create_mark (UAS_Pointer<UAS_Common> &, const Anchor &,
			     const char *name, const char *notes);

  void get_marks (UAS_Pointer<UAS_Common> &doc_ptr, xList<UAS_Pointer<Mark> > &list);

  void get_all_marks (xList<UAS_Pointer<Mark> > &list);

  bool read_only();

  void uncache_mark (Mark_mmdb *);

  static MarkBase *create (const char *filename, bool read_only);
  static MarkBase *open (const char *filename, bool read_only);

  // MMDB-only functions (for Mark_mmdb):
  operator mark_base *() const
    { return (f_mark_base); }

private:  // functions 
    Mark_mmdb *find_mark (oid_t &oid, UAS_Pointer<UAS_Common> &doc_ptr);
 
private: // variables
  mark_base         *f_mark_base;
  bool               f_read_only;
  xList<Mark_mmdb *> f_mark_cache;
};
