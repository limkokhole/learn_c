// ios_base -- ios_base basic members
#include <new>
#include <xdebug>
#include <xiosbase>
_STD_BEGIN

#define NSTDSTR 8   /* cin, wcin, cout, wcout, cerr, wcerr, clog, wclog */

_PGLOBAL _CRTDATA2 const streamoff _BADOFF = -1;    // initialize constant for bad file offset
_PGLOBAL _CRTDATA2 fpos_t _Fpz = {0};   // initialize constant for beginning of file

_MRTIMP2 fpos_t& __cdecl _Fpz_func() {
    return _Fpz;
}

_MRTIMP2 const streamoff& __cdecl _BADOFF_func() {
    return _BADOFF;
}

__PURE_APPDOMAIN_GLOBAL int ios_base::_Index = 0;   // initialize source of unique indexes
__PURE_APPDOMAIN_GLOBAL bool ios_base::_Sync = true;    // initialize synchronization flag
_MRTIMP2 int& ios_base::_Index_func() {
    return ios_base::_Index;
}
_MRTIMP2 bool& ios_base::_Sync_func() {
    return ios_base::_Sync;
}

__PURE_APPDOMAIN_GLOBAL static ios_base* stdstr[NSTDSTR + 2] =
{0};    // [1, NSTDSTR] hold pointers to standard streams
__PURE_APPDOMAIN_GLOBAL static char stdopens[NSTDSTR + 2] =
{0};    // [1, NSTDSTR] hold open counts for standard streams

//void __CLR_OR_THIS_CALL ios_base::clear(iostate state, bool reraise)
//  {   // set state, possibly reraise exception
//  _Mystate = (iostate)(state & _Statmask);
//  if ((_Mystate & _Except) == 0)
//      ;
//  else if (reraise)
//      _RERAISE;
//  else if (_Mystate & _Except & badbit)
//      _THROW(failure, "ios_base::badbit set");
//  else if (_Mystate & _Except & failbit)
//      _THROW(failure, "ios_base::failbit set");
//  else
//      _THROW(failure, "ios_base::eofbit set");
//  }

_MRTIMP2_NPURE void __cdecl ios_base::_Ios_base_dtor(ios_base* _This) {
    // destroy the object
    if (0 < _This->_Stdstr && 0 < --stdopens[_This->_Stdstr]) {
        return;
    }

    _This->_Tidy();
    _DELETE_CRT(_This->_Ploc);
}

//ios_base::_Iosarray& __CLR_OR_THIS_CALL ios_base::_Findarr(int idx)
//  {   // locate or make a variable array element
//  static _Iosarray stub(0, 0);
//  _Iosarray *p, *q;
//
//  if (idx < 0)
//      {   // handle bad index
//      setstate(badbit);
//      return (stub);
//      }
//
//  for (p = _Arr, q = 0; p != 0; p = p->_Next)
//      if (p->_Index == idx)
//          return (*p);    // found element, return it
//      else if (q == 0 && p->_Lo == 0 && p->_Vp == 0)
//          q = p;  // found recycling candidate
//
//  if (q != 0)
//      {   // recycle existing element
//      q->_Index = idx;
//      return (*q);
//      }
//
//  _Arr = _NEW_CRT _Iosarray(idx, _Arr);   // make a new element
//  return (*_Arr);
//  }

_MRTIMP2_NPURE void __cdecl ios_base::_Addstd(ios_base* _This) {
    // add standard stream to destructor list
    _BEGIN_LOCK(_LOCK_STREAM)

    for (_This->_Stdstr = 0; ++_This->_Stdstr < NSTDSTR;)
        if (stdstr[_This->_Stdstr] == 0 || stdstr[_This->_Stdstr] == _This) {
            break;    // found a candidate
        }

    stdstr[_This->_Stdstr] = _This;
    ++stdopens[_This->_Stdstr];
    _END_LOCK()
}

_STD_END

/*
 * Copyright (c) 1992-2005 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V4.05:0009 */
