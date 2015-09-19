/*
 * $XConsortium: NodeDict.hh /main/3 1996/06/11 16:26:55 cde-hal $
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


class NodeHandle;
class NodeObject;
class ObjectId;
class NodeMgr;

class NodeDict : public FolioObject
{
public: // functions
  NodeDict (NodeMgr &node_manager)
    : f_node_mgr (node_manager) { }
  NodeHandle &get_node_handle (const ObjectId &);
  void        forget_node_object (NodeObject &);

  NodeHandle *node_exists(const ObjectId &) const ;

protected: // functions

protected: // variables
  HashTbl  f_node_table;
  NodeMgr &f_node_mgr;
};

inline NodeHandle *
NodeDict::node_exists (const ObjectId &oid) const
{
  return (NodeObject*)f_node_table.find(oid) ;
}
