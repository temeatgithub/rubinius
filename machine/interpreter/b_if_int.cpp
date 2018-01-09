#include "instructions/b_if_int.hpp"

namespace rubinius {
  namespace interpreter {
    intptr_t b_if_int(STATE, CallFrame* call_frame, intptr_t const opcodes[]) {
      intptr_t location = argument(2);

      if(instructions::b_if_int(call_frame, argument(0), argument(1))) {
        call_frame->set_ip(location);
      } else {
        call_frame->next_ip(instructions::data_b_if_int.width);
      }

      return ((instructions::Instruction)opcodes[call_frame->ip()])(state, call_frame, opcodes);
    }
  }
}
