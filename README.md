# edcde
Extended Density Common Desktop Environment

On Debian/Ubuntu:

Run edcde.build.sh to install prerequisites and build.

- git (for downloading from source repository)
- build-essentials or build-essential
- libxp-dev
- libxt-dev
- libxmu-dev
- libxft-dev
- libxinerama-dev
- libxpm-dev
- libmotif or libmotif3 or libmotif4 (Openmotif, in non-free or restricted)
- libmotif-dev (Openmotif, in non-free or restricted)
- libxaw7-dev (used by dtinfo)
- libx11-dev
- libXSs-dev
- libtirpc-dev
- x11-xserver-utils (for xset)
- libjpeg62-turbo-dev
- libfreetype6-dev
- tcl-dev
- ksh (required for database to any script, and probably dtksh building)
- m4 (required for nsgmls building)
- ncompress (old style unix 'compress' needed when building help files)
- xfonts-100dpi (for nicer looking fonts)
- xfonts-100dpi-transcode or xfonts-100dpi-transcoded
- rpcbind (or portmap) requires running in insecure mode (-i) (create (ubuntu) or append (debian) the -i to OPTIONS in /etc/init.d/rpcbind
- bison
- xbitmaps

