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
/*
 * $XConsortium: index_desc.h /main/3 1996/06/11 17:32:22 cde-hal $
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


#ifndef _index_desc_h
#define _index_desc_h 1

#include "schema/stored_object_desc.h"
#include "schema/object_dict.h"

class index_desc : public stored_object_desc {

public:
   index_desc(int class_code, const char* comment = "");
   ~index_desc();

   void set_position(int x) { position = x; } ;
   void set_inv_nm(const char*) ;
   void set_agent_nm(const char*) ;

   char* get_inv_nm() { return inv_nm; };
   char* get_agent_nm() { return agent_nm; };

   virtual ostream& asciiOut(ostream& out, Boolean last = true);

protected:
   int position;

private:
   char* inv_nm;
   char* agent_nm;
};


class mphf_index_desc : public index_desc {

public:
   mphf_index_desc();
   ~mphf_index_desc() {};

   handler* init_handler(object_dict&) ;

protected:
};

class smphf_index_desc : public index_desc {

public:
   smphf_index_desc();
   ~smphf_index_desc() {};

   handler* init_handler(object_dict&) ;

protected:
};

class btree_index_desc : public index_desc {

public:
   btree_index_desc();
   ~btree_index_desc() {};

   handler* init_handler(object_dict&) ;

protected:
};


#endif
