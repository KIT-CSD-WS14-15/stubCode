#pragma once
#include <core/Module.h>
#include <iostream>

/** This is a very simple module meant to separate events on stdout. */
class NewEventPrinterModule : public Module {
public:
  /** Prints a separation line. */
  void event() override {
    std::cout << "====================================================" << std::endl;
  }
};
