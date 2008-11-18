#!/bin/bash

cat << _EOF
>>	Shaman Building script.
>>	This is not an installation script, it will just build shaman
>>	and set up the SUID bit.
_EOF

mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make
sudo chown root shaman
sudo chmod u+s shaman

#sudo make install
