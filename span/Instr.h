//===----------------------------------------------------------------------===//
//  MIT License.
//  Copyright (c) 2019 GRC Lab, CSE Dept., IIT Bombay, India
//
//  Author: Anshuman Dhuliya [AD] (dhuliya@cse.iitb.ac.in)
//
//===----------------------------------------------------------------------===//

#ifndef SPAN_INSTR_H
#define SPAN_INSTR_H

namespace span {
  namespace ir {
    /// The instructions (three-address).
    namespace instr {
      class InstrT {

      };

      class AssignI : public InstrT {

      };

      class CallI : public InstrT {

      };

      class ReturnI : public InstrT {

      };

    } // end namespace instr
  } // end namespace ir
} // end namespace span

#endif //SPAN_INSTR_H
