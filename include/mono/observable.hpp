#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace obs {
template <typename T>
class Observable {
 public:
  using Watcher = std::function<void(const std::string&, const T&)>;

  void set(const std::string& key, const T& value) {
    data[key] = value;
    notify(key, value);
  }

  const T& get(const std::string& key) const { return data.at(key); }

  void watch(Watcher w) { watchers.push_back(w); }

  class Proxy {
    Observable& obs;
    std::string key;

   public:
    Proxy(Observable& o, const std::string& k) : obs(o), key(k) {}

    Proxy& operator=(const T& value) {
      obs.data[key] = value;
      obs.notify(key, value);
      return *this;
    }

    operator T() const {
      auto it = obs.data.find(key);
      if (it != obs.data.end()) return it->second;
      return T{};
    }
  };

  Proxy operator[](const std::string& key) { return Proxy(*this, key); }

 private:
  std::unordered_map<std::string, T> data;
  std::vector<Watcher> watchers;

  void notify(const std::string& key, const T& value) {
    for (auto& w : watchers) w(key, value);
  }
};
}