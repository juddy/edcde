// $XConsortium: MMDB_Factory.hh /main/6 1996/10/04 12:35:04 cde-hal $
#ifndef _MMDB_Factory_hh_
#define _MMDB_Factory_hh_

#include "UAS_Factory.hh"
#include "UAS_PtrList.hh"
#include "MMDB.hh"

class MMDB_URL {
    public:
	MMDB_URL();

    public:
	void locator (const UAS_String &);
	UAS_String locator();
	void installPair (const UAS_String &key, const UAS_String &value);
    public:
	UAS_String fInfoLib;
	UAS_String fInfoBase;
	//
	//  Valid values for fType are:
	//	section
	//	collection
	//	embedded
	//
	UAS_String fType;
	UAS_String fLocator;
};

class MMDB_Factory: public UAS_Factory {
    friend class MMDB;
    public:
	MMDB_Factory ();
	~MMDB_Factory ();
    protected:
	UAS_List<UAS_String> rootLocators ();
	void destroy_root_object (UAS_Pointer<UAS_Common>);
	MMDB *getMMDB (const UAS_String &infoLibPath);
	MMDB *createMMDB (const UAS_String &infoLibPath);
	MMDB *getMMDBFromObject (UAS_Pointer<UAS_Common>);
	void resolveLocator (const UAS_String &, MMDB *&, info_base *&);
	UAS_Pointer<UAS_Common> create_object(const UAS_String& abs_locator);
	UAS_Pointer<UAS_Common> create_relative_object(
		    const UAS_String& rel_locator,
		    UAS_Pointer<UAS_Common> parent
		);
	UAS_Pointer<UAS_EmbeddedObject> create_embedded_object(
		    const UAS_String& rel_locator
		);
	UAS_Pointer<UAS_EmbeddedObject> create_relative_embedded_object(
		    const UAS_String& rel_locator,
		    UAS_Pointer<UAS_Common> parent
		);
	void initializeFactory(UAS_List<UAS_String>&);
	void finalizeFactory();
	static OLIAS_DB &olias_db();
	static UAS_String genInfolibName ();
    private:
	static OLIAS_DB *fOLIASDB;
	UAS_PtrList<MMDB> fMMDBList;
	UAS_PtrList<MMDB> fDeadMMDBList;
};

#endif
