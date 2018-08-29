/*
 * patterns.h
 *
 *  Created on: May 31, 2012
 *      Author: Andy
 */

#ifndef PATTERNS_H_
#define PATTERNS_H_

#include <assert.h>

#include "abstract_factory.h"
#include "adapter.h"
#include "bridge.h"
#include "builder.h"
#include "chain_of_responsibility.h"
#include "command.h"
#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "factory_method.h"
#include "flyweight.h"
#include "interpreter.h"
#include "lazy_initialization.h"
#include "mediator.h"
#include "memento.h"
#include "observer.h"
#include "profiler.h"
#include "prototype.h"
#include "proxy.h"
#include "state.h"
#include "strategy.h"
#include "template_method.h"
#include "visitor.h"

namespace patterns {

int test() {
  assert(abstract_factory::test());
  assert(adapter::test());
  assert(bridge::test());
  assert(builder::test());
  assert(chain_of_responsibility::test());
  assert(command::test());
  assert(composite::test());
  assert(decorator::test());
  assert(facade::test());
  assert(factory_method::test());
  assert(flyweight::test());
  assert(interpreter::test());
  assert(lazy_initialization::test());
  assert(mediator::test());
  assert(memento::test());
  assert(observer::test());
  assert(profiler::test());
  assert(prototype::test());
  assert(proxy::test());
  assert(state::test());
  assert(strategy::test());
  assert(template_method::test());
  assert(visitor::test());
  return 1;
}

}  // namespace patterns

#endif /* PATTERNS_H_ */
