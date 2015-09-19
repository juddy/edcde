/*
 * $XConsortium: Sender.hh /main/5 1996/09/27 19:02:39 drk $
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

#ifndef _Sender_hh
#define _Sender_hh

template <class T> class Receiver;

template <class T>
class Sender
{
public:
  Sender()
    { ON_DEBUG (printf ("Sender::Sender() 0x%p\n", this)); }
  ~Sender();

  void send_message (const T &message);

  // Request message T.
  void request (Receiver<T> *receiver);
  // Stop receiving message T.
  void unrequest (Receiver<T> *receiver);

private:
  // Keep track of message receivers so that we can send them messages
  // and notify them when we have been destroyed.
  xList<Receiver<T> *> f_receiver_list;
};

#define STATIC_SENDER_HH(T)				\
  static void send_message (const T &message)		\
    { CONCAT(sender,T)().send_message (message); }	\
  static void request (Receiver<T> *receiver)		\
    { CONCAT(sender,T)().request (receiver); }		\
  static void unrequest (Receiver<T> *receiver)		\
    { CONCAT(sender,T)().unrequest (receiver); }	\
  static Sender<T> &CONCAT(sender,T)()

#define STATIC_SENDER_CC(T) \
  Sender<T> &CLASS::CONCAT(sender,T)() { \
    static Sender<T> CONCAT(f_sender,T); \
    return (CONCAT(f_sender,T)); }

#ifdef EXPAND_TEMPLATES
#include "Sender.C"
#endif

#endif /* _Sender_hh */
/* DO NOT ADD ANY LINES AFTER THIS #endif */
