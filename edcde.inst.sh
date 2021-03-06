#!/bin/bash

#Check for X and the Korn Shell and install them if they aren't there.
#If you do this yourself, $sudo apt-get install xorg ksh should be work.
problem=$(dpkg -s xorg|grep installed)

echo Checking for X: $problem
 if [ "" == "$problem" ]; then
      echo "No X.Org. Setting up X.Org"
      sudo apt-get --yes install xorg
 fi

problem=$(dpkg -s ksh|grep installed)
 echo Checking for the Korn Shell: $problem
 if [ "" == "$problem" ]; then
      echo "No ksh. Setting up the Korn Shell"
      sudo apt-get --yes install ksh
 fi

#Extract precompiled CDE in to /usr
#This version of the CDE package includes libXm, libXp, and libjpeg in /usr/dt/lib
#This eliminates the need to install OpenMotif and the  other dependencies and
#was done to keep size at at minimum. Note that this is kludgy but works and none
#of the libs included were modified.
tar xvzf dtpluslibs.tar.gz -C /usr

#Create and make world-writable /var/dt
mkdir -p /var/dt
chmod a+rwx /var/dt

#Create Calendar Spool file for dtcm
mkdir -p /usr/spool/calendar

#Copy startCDE script and make executable
cp startCDE /usr/local/bin
chmod +x /usr/local/bin/startCDE

echo "Finished, try starting EDCDE with startCDE"

