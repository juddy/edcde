// $TOG: DtSR_BookcaseEntry.hh /main/8 1998/04/17 11:41:33 mgreess $
/*	Copyright (c) 1995,1996 FUJITSU LIMITED		*/
/*	All Rights Reserved				*/

#ifndef _DTSR_BOOKCASEENTRY_HH_
#define _DTSR_BOOKCASEENTRY_HH_

#include "UAS_BookcaseEntry.hh"
#include "UAS_Base.hh"
#include "UAS_List.hh"
#include "UAS_SearchZones.hh"

#include "DtSR_Stems.hh"

extern "C" {
#include "Search.h"
}

class DtSR_BookcaseEntry : public UAS_BookcaseEntry
{
  public:
    DtSR_BookcaseEntry(UAS_Pointer<UAS_Common>& bookcase, int searchable = 0)
			: UAS_BookcaseEntry(bookcase, searchable) { };
    virtual ~DtSR_BookcaseEntry() { };
  
};

class DtSR_BookcaseSearchEntry : public DtSR_BookcaseEntry
{
  friend class DtSR_SearchEngine;

  public:
    DtSR_BookcaseSearchEntry(int dbn, UAS_Pointer<UAS_Common>& bc,
				      int searchable = 0);
    virtual ~DtSR_BookcaseSearchEntry();

    short	language() { return f_language; }

    UAS_Pointer<DtSR_Stems>& stems() { return f_stems; }
    UAS_Pointer<DtSR_Stems>  takeover_stems();

    static void search_zones(UAS_SearchZones& search_zones);

    UAS_Pointer<UAS_Common> bcase() { return uas_bcase; }


#if !defined(SC3) && !defined(__osf__) && !defined(USL) && !defined(linux)

  protected:
    template <class T> friend class UAS_Pointer;

#endif

    virtual void unreference();

  private:
    void _search_zones(UAS_SearchZones& search_zones);

    UAS_Pointer<UAS_String>	f_dbname;
    int				f_dbn;

    short			f_language;

    DtSrKeytype*		f_keytypes;
    int				f_ktcount;

    UAS_Pointer<DtSR_Stems> f_stems;

    // list of bookcases to which this belongs
    static UAS_Pointer<UAS_List<DtSR_BookcaseSearchEntry> > f_bcases;
    static UAS_List<DtSR_BookcaseSearchEntry> &bcases();

    UAS_Pointer<UAS_Common> uas_bcase;
};

#endif
