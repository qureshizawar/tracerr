wget https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/protobuf-cpp-3.6.1.tar.gz
tar -xzf protobuf-cpp-3.6.1.tar.gz
cd protobuf-3.6.1 && ./configure && make && make check && make install && ldconfig
