/*
 * $XConsortium: NodeDisplayDataTml.hh /main/3 1996/06/11 16:20:42 cde-hal $
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

class model;
class NodeObject;
class NodeHandle;

class NodeDisplayData : public FolioObject
{
public: // functions
  NodeDisplayData (NodeObject &node_object)
    : f_node_object (node_object), f_model (NULL), 
      f_font_serial(0), f_model_serial (0)
    { }

  ~NodeDisplayData();
  model &the_model();

  // traverse tml data and update fonts - should be improved via tml - jbm
  void update_fonts(unsigned int serial_number);

  // for NodeObject use only 
  void not_displayed();

  NodeHandle &node_handle()
    { return ((NodeHandle &) f_node_object); }

  HashTbl &locator_table()
    { return (f_locator_table); }

  u_int model_serial()
    { return (f_model_serial); }

protected: // variables
  NodeObject &f_node_object;
  model      *f_model;   // TML object

  unsigned int f_font_serial;
  // NOTE: the elements in the locator table must be freed when model killed!! 
  HashTbl      f_locator_table;
  // We keep track of a unique serial number with each model so that it is
  // easy to tell if the model has changed by comparing serial numbers. 
  u_int        f_model_serial;
};
