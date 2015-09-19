// $XConsortium: DtSR_SearchResultsEntry.hh /main/6 1996/06/11 16:41:32 cde-hal $
#ifndef _DTSR_SEARCHRESULTSENTRY_HH_
#define _DTSR_SEARCHRESULTSENTRY_HH_

#include "UAS_Pointer.hh"
#include "UAS_SearchResultsEntry.hh"
#include "DtSR_SearchZones.hh"

class DtSR_SearchResults;

class DtSR_SearchResultsEntry : public UAS_SearchResultsEntry
{
  public:

    DtSR_SearchResultsEntry(const char* id, const char* book,
			    const char* section, int dbn, short language,
			    UAS_Pointer<DtSR_SearchResults>);
    ~DtSR_SearchResultsEntry();

    UAS_Pointer<UAS_List<UAS_TextRun> > matches() const;

    // calculates relevance based on f_proximity values
    unsigned int relevance();

    UAS_Pointer<UAS_List<UAS_TextRun> > create_matches();

    enum relevances { Utmost_Relevance = 999, Inv_Relevance = -1 };

    enum errors { Beyond_Range = -1, Unspecified = -2, Conflict = -3 };

    int set_proximity(DtSR_SearchZones::uas_zones zone, int proximity);
    int unset_proximity(DtSR_SearchZones::uas_zones zone);
    int get_proximity(DtSR_SearchZones::uas_zones zone) const;
    int overlay_proximity(DtSR_SearchZones::uas_zones, int proximity);

    int dbn() const { return f_dbn; }
    void dbn(int n) { f_dbn = n; }

    unsigned int zone() const { return f_zone; }

    // return section
    static UAS_Pointer<UAS_String>
	parse_abstract(const char* abstract, UAS_Pointer<UAS_String> &id,
	    UAS_Pointer<UAS_String> &book, UAS_Pointer<UAS_String> &section);
    static int section_in_abstract(char* abstract, const char* id);

    UAS_Pointer<DtSR_SearchResults> &
	search_result() { return f_search_res; }

    UAS_Pointer<DtSR_SearchResults>
	search_result(UAS_Pointer<DtSR_SearchResults> &);

  protected:
    friend class UAS_Pointer<DtSR_SearchResultsEntry>;
    virtual void	unreference();

  private:
    int			f_dbn;		// database number
    short		f_language;	// language of the database
    unsigned int	f_zone;		// bitmask
    int			f_proximity[UAS_SearchZones::uas_all + 1];

    UAS_Pointer<DtSR_SearchResults> f_search_res;

};

#endif
