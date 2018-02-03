#ifndef RBX_DIAGNOSTICS_CONCURRENCY_HPP
#define RBX_DIAGNOSTICS_CONCURRENCY_HPP

#include "diagnostics/diagnostic.hpp"

namespace rubinius {
  namespace diagnostics {
    struct LockMetrics : public Diagnostic {
      metric stop_the_world_ns;

      LockMetrics()
        : Diagnostic()
        , stop_the_world_ns(0)
      {
        set_type("ConcurrencyMetrics");
      }

      virtual void start_reporting(STATE) {
        if(state->shared().config.diagnostics_machine_enabled) {
          Diagnostic::start_reporting(state);
        }
      }

      virtual void stop_reporting(STATE) {
        if(state->shared().config.diagnostics_machine_enabled) {
          Diagnostic::stop_reporting(state);
        }
      }
    };
  }
}

#endif
