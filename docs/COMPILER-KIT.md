# Build and Install FCC


These instructions are all gathered from a fresh install of Ubuntu-24.04 on
WSL2.

## Compiler Kit

```bash
git clone https://codeberg.org/etchedPixels/FUZIX-Bintools.git
git clone https://codeberg.org/etchedPixels/FUZIX-Compiler-Kit.git

sudo mkdir /opt/fcc
sudo chown ${USER}:${USER} /opt/fcc
echo "export PATH=\"$PATH:/opt/fcc/bin\"" >> ${HOME}/.bashrc
source ${HOME}/.bashrc

sudo apt update
sudo apt install build-essential libbsd-dev
cd FUZIX-Bintools
make install
cd ../FUZIX-Compiler-Kit
make bootstuff
make install
```
<!-- vim: tw=80 cc=80 ft=markdown: -->
