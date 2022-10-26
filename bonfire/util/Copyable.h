#ifndef BONFIRE_COPYABLE_H__
#define BONFIRE_COPYABLE_H__

namespace bonfire {

class Copyable {
 protected:
  Copyable() = default;
  ~Copyable() = default;
};

} // namespace bonfire

#endif  // BONFIRE_COPYABLE_H__