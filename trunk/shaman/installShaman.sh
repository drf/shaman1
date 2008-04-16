#!/bin/bash

cat << _EOF
>>	Shaman Building script.
>>	This is not an installation script, it will just build shaman
>>	and set up the SUID bit.
_EOF

cmake . -DCMAKE_INSTALL_PREFIX=/usr
make
sudo make install
sudo chown root /usr/bin/shaman
sudo chmod u+s /usr/bin/shaman

#sudo make install
