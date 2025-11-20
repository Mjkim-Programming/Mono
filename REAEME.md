# Mono
 Mono is a C++ library that implements **Observables** based on template.

## Key Features
- Assign Watcher to notify set() or operator[] = value
- Can detect state[key] = value using operator[] Proxy
 
## Install & Build
```bash
$ git clone https://github.com/Mjkim-Programming/Mono
$ cd Mono

$ chmod +x ./install.sh
$ ./install.sh
```

## Example
```cpp
#include <mono/observable.hpp>
#include <iostream>

int main() {
    obs::Observable<int> obs;

    obs.watch([](const std::string& key, const int& value){
        std::cout << "Changed: " << key << " = " << value << "\n";
    });

    obs.set("a", 42);
    obs["b"] = 100;

    std::cout << obs.get("a") << "\n";   // 42
    std::cout << int(obs["b"]) << "\n";  // 100
}
```

## Contributing
Contributions are welcome! There are no strict coding rules yet, so feel free to contribute. We’ll refine guidelines as the project grows.