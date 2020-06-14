#wget https://github.com/protocolbuffers/protobuf/releases/download/v3.12.3/protobuf-cpp-3.12.3.tar.gz
#tar -xzf protobuf-cpp-3.12.3.tar.gz
#cd protobuf-3.12.3 && ./configure && make && make check && sudo make install # && ldconfig
brew install protobuf@3.6
echo 'export PATH="/usr/local/opt/protobuf@3.6/bin:$PATH"' >> /Users/travis/.bash_profile 
export LDFLAGS="-L/usr/local/opt/protobuf@3.6/lib" 
export CPPFLAGS="-I/usr/local/opt/protobuf@3.6/include" 
export PKG_CONFIG_PATH="/usr/local/opt/protobuf@3.6/lib/pkgconfig"
