/*
 * Copyright (C) 2012 Alec Thomas <alec@swapoff.org>
 * All rights reserved.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *
 * Author: Alec Thomas <alec@swapoff.org>
 */

#pragma once

#include <boost/timer.hpp>
#include "entityx/Entity.h"
#include "entityx/Event.h"
#include "entityx/System.h"

namespace entityx {

class Manager {
 public:
  Manager() :
    event_manager(EventManager::make()),
    entity_manager(EntityManager::make(event_manager)),
    system_manager(SystemManager::make(entity_manager, event_manager)) {}
  virtual ~Manager() {}

  void start();
  void run();
  void stop();

 protected:
  /**
   * Configure the world.
   *
   * This is called once on Manager initialization. It is typically used to add Systems to the world, load permanent
   * resources, global configuration, etc.
   */
  virtual void configure() = 0;

  /**
   * Initialize the entities and events in the world.
   *
   * Typically used to create initial entities, setup event handlers, and so on.
   */
  virtual void initialize() = 0;

  /**
   * Update the world.
   *
   * Typically this is where you would call update() on all Systems in the world.
   */
  virtual void update(double dt) = 0;

  entityx::shared_ptr<EventManager> event_manager;
  entityx::shared_ptr<EntityManager> entity_manager;
  entityx::shared_ptr<SystemManager> system_manager;

 private:
  boost::timer timer_;
  bool running_ = false;
};

}
