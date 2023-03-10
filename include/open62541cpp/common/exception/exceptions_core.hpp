#ifndef EXCEPTIONS_CORE_HPP
#define EXCEPTIONS_CORE_HPP

#include <cstdint>
#include <exception>

namespace opcua {
namespace diag {

class OpcuaException : public std::exception {
public:
  OpcuaException() = default;
  virtual ~OpcuaException() = default;
};

class BadStatusException : public OpcuaException {
public:
  BadStatusException() = default;
  virtual ~BadStatusException() = default;
};

class GoodStatusException : public OpcuaException {
public:
  GoodStatusException() = default;
  virtual ~GoodStatusException() = default;
};

class UncertainStatusException : public OpcuaException {
public:
  UncertainStatusException() = default;
  virtual ~UncertainStatusException() = default;
};

class OpcuaUnknownException : public OpcuaException {
public:
  OpcuaUnknownException() = default;
  virtual ~OpcuaUnknownException() = default;
};

}  // namespace diag
}  // namespace opcua

#endif // EXCEPTIONS_CORE_HPP