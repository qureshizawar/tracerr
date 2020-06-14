wget https://github.com/protocolbuffers/protobuf/releases/download/v3.12.3/protobuf-cpp-3.12.3.tar.gz
tar -xzf protobuf-cpp-3.12.3.tar.gz
cd protobuf-3.12.3 && ./configure --disable-dependency-tracking && make && make check && make install # && ldconfig
