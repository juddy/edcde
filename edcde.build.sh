#!/bin/bash


if [ ! -f /etc/debian_version ]
then
	echo "Oops, $0 only runs on Debian/Ubuntu systems, or systems with dpkg and apt available"
	exit 1
fi
#Checking for and installing missing prerequisites

#git
prereq=$(dpkg -s git|grep installed)
 echo Checking for git: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing git..."
      sudo apt-get --yes install git
 fi

#build-essential
prereq=$(dpkg -s build-essential|grep installed)
 echo Checking for Build Tools: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing build-essential..."
      sudo apt-get --yes install build-essential
 fi

#ncompress
prereq=$(dpkg -s ncompress|grep installed)
 echo Checking for compress: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing ncompress..."
      sudo apt-get --yes install ncompress
 fi

#tcl-dev
prereq=$(dpkg -s tcl-dev|grep installed)
 echo Checking for tcl: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing tcl..."
      sudo apt-get --yes install tcl-dev
 fi

#bison
prereq=$(dpkg -s bison|grep installed)
 echo Checking for bison: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing buffalumps..."
      sudo apt-get --yes install bison
 fi

#libxft-dev
prereq=$(dpkg -s libxft-dev|grep installed)
 echo Checking for libxft: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing libxft..."
      sudo apt-get --yes install libxft-dev
 fi

#libxmu-dev
prereq=$(dpkg -s libxmu-dev|grep installed)
 echo Checking for libxmu: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing libxmu..."
      sudo apt-get --yes install libxmu-dev
 fi

#libxp-dev
prereq=$(dpkg -s libxp-dev|grep installed)
 echo Checking for libxp: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing libxp..."
      sudo apt-get --yes install libxp-dev
 fi

#libfreetype6-dev
prereq=$(dpkg -s libfreetype6-dev|grep installed)
 echo Checking for libfreetype6: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing libfreetype..."
      sudo apt-get --yes install libfreetype6-dev
 fi

#libjpeg-dev
prereq=$(dpkg -s libjpeg62-dev|grep installed)
 echo Checking for libjpeg: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing libjpeg..."
      sudo apt-get --yes install libjpeg62-dev
 fi

#libxaw
prereq=$(dpkg -s libxaw7-dev|grep installed)
 echo Checking for libxaw: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing libxaw..."
      sudo apt-get --yes install libxaw7-dev
 fi

echo "All free prerequisites installed..."

#enable non-free repo, get and install OpenMotif
#don't need it on CDEbian, non-free already enabled.
#sudo sh -c 'echo "deb http://http.us.debian.org/debian squeeze non-free" >> /etc/apt/sources.list'
#sudo apt-get update

#OpenMotif
prereq=$(dpkg -s libmotif-dev|grep installed)
 echo Checking for OpenMotif: $prereq
 if [ "" == "$prereq" ]; then
      echo "Installing OpenMotif..."
      sudo apt-get --yes install libmotif-dev
 fi

echo "OpenMotif and OpenMotif Development libraries installed..."

#Pull from github

git pull

#Link X11 headers
mkdir -p imports/x11/include
cd imports/x11/include
ln -s /usr/include/X11 .
cd ../../..

#Build...Make World (or World.dev/World.doc)

make World

#Install CDE to /usr/dt

make install

# Add palettes

echo "Installing palettes"

cp -aR programs/palettes /usr/dt

cd admin/IntegTools/dbTools
sudo ./installCDE -s ../../..
cd ../post_install/linux
sudo ./configRun -e
sudo mkdir -p /var/dt
sudo chmod -R a+rwx /var/dt
sudo mkdir -p /usr/spool/calendar

