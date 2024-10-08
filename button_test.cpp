#include "react.h"

int main() {
  _init();

  _put_raw(20, "button");

  add_yaml("button.yaml", {{"id", 0}});
  add_yaml("button.yaml", {{"id", 1}});
  add_yaml("button.yaml", {{"id", 2}});

  _quit();
}
