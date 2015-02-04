// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_INTERNAL_EOLF_HH
#define PEGTL_INTERNAL_EOLF_HH

#include "../analysis/generic.hh"

namespace pegtl
{
   namespace internal
   {
      struct eolf
      {
         using analyze_t = analysis::generic< analysis::rule_type::OPTIONAL >;

         template< typename Input >
         static bool match( Input & in )
         {
            if ( in.empty() ) {
               return true;
            }
            else if ( in.peek_char() == '\n' ) {
               in.bump();
               return true;
            }
            return false;
         }
      };

   } // internal

} // pegtl

#endif
