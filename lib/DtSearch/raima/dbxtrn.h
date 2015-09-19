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
/* $XConsortium: dbxtrn.h /main/2 1996/05/09 04:04:00 drk $ */
/*
 *   COMPONENT_NAME: austext
 *
 *   FUNCTIONS: none
 *
 *   ORIGINS: 157
 *
 */
/*----------------------------------------------------------------------------
   dbxtrn.h: db_VISTA external data header file

   (This file is included by dbtype.h)

   (C) Copyright 1984 by Raima Corporation.
----------------------------------------------------------------------------*/

/* ********************** EDIT HISTORY *******************************

 SCR    DATE    INI                   DESCRIPTION
----- --------- --- -----------------------------------------------------
  423 22-Sep-88 RSC Cleanup file to compile under Lattice
  368 23-Sep-88 RSC Changed defn of Last_mtype to match dbtype.h
  439 17-Nov-88 RSC Integrate 3.10 branch (w/o windows) into main
  440 13-Dec-88 RSC LR_LOCK was removed from db_global for general LM
  532 06-Jan-89 RSC Fixed defns of rn_dba/type,db_name for ONE_DB
      05-May-89 WLW Changed TASK_P to DB_TASK for query multi-tasking

*/

/* Database Dictionary Tables */
extern INT largest_page;

#ifndef ONE_DB
extern INT old_size_ft;
extern INT old_size_fd;
extern INT old_size_st;
extern INT old_size_mt;
extern INT old_size_srt;
extern INT old_size_kt;
extern INT old_size_rt;
extern INT old_no_of_dbs;
#else
#define old_size_ft 0
#define old_size_fd 0
#define old_size_st 0
#define old_size_mt 0
#define old_size_srt 0
#define old_size_kt 0
#define old_size_rt 0
#define old_no_of_dbs 0
#endif

extern char FAR *crloc;          /* location in page buffer of current record */

typedef struct TASK_S {
   /* The following global variables came from dblfcns.c */
#ifndef SINGLE_USER
   int Lock_tries;            /* lock_tries = 5 */
   int Dbwait_time;           /* dbwait_time = 1 */
   int Db_timeout;            /* db_timeout = TIMEOUT_DEF */
#endif
   int Dbopen;                /* dbopen = 0 */
#ifndef SINGLE_USER
   int Db_lockmgr;            /* db_lockmgr = 1 */
#endif
   char Dbuserid[FILENMLEN];  /* dbuserid = "" */
   char Dbdpath[FILENMLEN*2]; /* dbdpath = "" */
   char Dbfpath[FILENMLEN*2]; /* dbdpath = "" */
#ifndef SINGLE_USER
   INT_P App_locks;           /* app_locks = NULL */
   INT_P Excl_locks;          /* excl_locks = NULL */
   INT_P Kept_locks;          /* kept_locks = NULL */
#endif
   CONST char FAR *Trans_id;  /* trans_id = NULL */
   char Dblog[FILENMLEN];     /* dblog = "" */
#ifndef SINGLE_USER
   LOCK_DESCR_P Rec_locks;    /* rec_locks = NULL */
   LOCK_DESCR_P Set_locks;    /* set_locks = NULL */
   LOCK_DESCR_P Key_locks;    /* key_locks = NULL */
   int Keyl_cnt;
   int Lp_size;
   int Fp_size;
   LM_LOCK_P Lock_pkt;        /* lock_pkt = NULL */
   LM_FREE_P Free_pkt;        /* free_pkt = NULL */
   FILE_NO_P File_refs;
   int Lsn;
   BOOLEAN Session_active;    /* session_active = FALSE */
#endif
   /* The following global variables came from dio.c */
   BOOLEAN Cache_ovfl;        /* cache_ovfl = FALSE */
   PGZERO_P Pgzero;	      /* database file page 0 array */
   /* The following global variables came from keyfcns.c */
   int No_of_keys;            /* no_of_keys = 0 */
   KEY_INFO_P Key_info;       /* key_info = NULL */
   KEY_TYPE Key_type;
   /* The following global variables came from netwdos.c */
   int Net_status;
   LONG Last_mtype;
   /* The following global variables came from options.c */
   int Dboptions;             /* ifdef NO_TRANS: dboptions =
							DCHAINUSE | TRLOGGING
			         else:           dboptions = DCHAINUSE */
   /* The following global variables came from ovfcns.c */
   long Ov_initaddr;          /* ov_initaddr = 0L */
   long Ov_rootaddr;          /* ov_rootaddr = 0L */
   long Ov_nextaddr;          /* ov_nextaddr = 0L */
   RI_ENTRY_P Root_ix;
   /* The following global variables came from renfiles.c */
   llist Ren_list;	      /* Ren_list = LLIST_INIT() */
   /* The following global variables came from inittab.h */
   INT Page_size;
#ifndef ONE_DB
   int     Curr_db;
   DB_ENTRY FAR *Curr_db_table;
#endif
   DB_ADDR Curr_rec;          /* current record address */
   DB_ADDR_P Curr_own;        /* current set owners array */
   DB_ADDR_P Curr_mem;        /* current set members array */
#ifndef	 NO_TIMESTAMP
   ULONG   Cr_time;
   ULONG_P Co_time;          /* co_time = NULL */
   ULONG_P Cm_time;          /* cm_time = NULL */
   ULONG_P Cs_time;          /* cs_time = NULL */
   BOOLEAN Db_tsrecs;
   BOOLEAN Db_tssets;
#endif
   FILE_NO Ov_file;
#ifndef ONE_DB
   BOOLEAN Setdb_on;
   INT No_of_dbs;
   RN_ENTRY_P Rn_table;
   RN_ENTRY FAR *Curr_rn_table;
#else
   DB_ADDR rn_dba;	 /* last computed dba by recfrst/recset/recnext */
   INT     rn_type;	 /* last record type supplied to recfrst/recset */
   INT     Ft_offset;
#endif
#ifndef	 ONE_DB
   DB_ENTRY_P Db_table;
#else
   char db_name[DBNMLEN];   /* name of this database */
   char db_path[PATHLEN];   /* name of path to this database */
   DB_ADDR sysdba;  /* database address of system record */
#endif
   FILE_ENTRY_P File_table;
   INT Size_ft;
   RECORD_ENTRY_P Record_table;
   INT Size_rt;
   SET_ENTRY_P Set_table;
   INT Size_st;
   MEMBER_ENTRY_P Member_table;
   INT Size_mt;
   SORT_ENTRY_P Sort_table;
   INT Size_srt;
   FIELD_ENTRY_P Field_table;
   INT Size_fd;
   KEY_ENTRY_P Key_table;
   INT Size_kt;
   int Lock_lvl;
#define LOCK_STACK_SIZE		10
   int Lock_stack[LOCK_STACK_SIZE];
#ifndef NO_COUNTRY
   CNTRY_TBL_P country_tbl;
   int ctbl_activ;
   char ctbpath[FILENMLEN];
#endif
   llist Sk_list;
} TASK;

/* Dynamically allocated global variables */
#define app_locks db_global.App_locks.ptr
#define excl_locks db_global.Excl_locks.ptr
#define kept_locks db_global.Kept_locks.ptr
#define rec_locks db_global.Rec_locks.ptr
#define set_locks db_global.Set_locks.ptr
#define key_locks db_global.Key_locks.ptr
#define lock_pkt db_global.Lock_pkt.ptr
#define free_pkt db_global.Free_pkt.ptr
#define file_refs db_global.File_refs.ptr
#define key_info db_global.Key_info.ptr
#define curr_own db_global.Curr_own.ptr
#define curr_mem db_global.Curr_mem.ptr
#define rn_table db_global.Rn_table.ptr
#define db_table db_global.Db_table.ptr
#define file_table db_global.File_table.ptr
#define record_table db_global.Record_table.ptr
#define set_table db_global.Set_table.ptr
#define member_table db_global.Member_table.ptr
#define sort_table db_global.Sort_table.ptr
#define field_table db_global.Field_table.ptr
#define key_table db_global.Key_table.ptr
#define pgzero db_global.Pgzero.ptr
#define root_ix db_global.Root_ix.ptr
#ifndef NO_TIMESTAMP
#define co_time db_global.Co_time.ptr
#define cm_time db_global.Cm_time.ptr
#define cs_time db_global.Cs_time.ptr
#endif
/* Used in DIO.C and OVFCNS.C */
#define ixpg_table Ixpg_table.ptr
#define dbpgbuff Dbpgbuff.ptr
#define ix_lookup Ix_lookup.ptr

/* Non-dynamically allocated global variables */
#define lock_tries db_global.Lock_tries
#define dbwait_time db_global.Dbwait_time
#define db_timeout db_global.Db_timeout
#define dbopen db_global.Dbopen
#define db_lockmgr db_global.Db_lockmgr
#define dbuserid db_global.Dbuserid
#define dbdpath db_global.Dbdpath
#define dbfpath db_global.Dbfpath
#define trans_id db_global.Trans_id
#define dblog db_global.Dblog
#define keyl_cnt db_global.Keyl_cnt
#define lp_size db_global.Lp_size
#define fp_size db_global.Fp_size
#define session_active db_global.Session_active
#define cache_ovfl db_global.Cache_ovfl
#define no_of_keys db_global.No_of_keys
#define key_type db_global.Key_type
#define net_status db_global.Net_status
#define last_mtype db_global.Last_mtype
#define dboptions db_global.Dboptions
#define ov_initaddr db_global.Ov_initaddr
#define ov_rootaddr db_global.Ov_rootaddr
#define ov_nextaddr db_global.Ov_nextaddr
#define page_size db_global.Page_size
#define curr_db db_global.Curr_db
#define curr_db_table db_global.Curr_db_table
#define curr_rec db_global.Curr_rec
#ifndef	NO_TIMESTAMP
#define cr_time db_global.Cr_time
#define db_tsrecs db_global.Db_tsrecs
#define db_tssets db_global.Db_tssets
#endif
#define ov_file db_global.Ov_file
#ifndef ONE_DB
#define setdb_on db_global.Setdb_on
#define no_of_dbs db_global.No_of_dbs
#define curr_rn_table db_global.Curr_rn_table
#endif
#define size_ft db_global.Size_ft
#define size_rt db_global.Size_rt
#define size_st db_global.Size_st
#define size_mt db_global.Size_mt
#define size_srt db_global.Size_srt
#define size_fd db_global.Size_fd
#define size_kt db_global.Size_kt
#define lock_lvl db_global.Lock_lvl
#define lock_stack db_global.Lock_stack
#define ren_list db_global.Ren_list
#define sk_list db_global.Sk_list

extern TASK db_global;
extern int db_glob_init;
#ifdef MULTI_TASK
extern DB_TASK Currtask;
#endif


#ifdef MULTI_TASK
extern int task_count;
#endif
/* vpp -nOS2 -dUNIX -nBSD -nVANILLA_BSD -nVMS -nMEMLOCK -nWINDOWS -nFAR_ALLOC -f/usr/users/master/config/nonwin dbxtrn.h */
