# BSY Vagrant Box for OS X & Windows
### Install VirtualBox and Vagrant
Get Virtualbox from
<a href="https://www.virtualbox.org/wiki/Downloads">https://www.virtualbox.org/wiki/Downloads</a>

Afterwards Vagrant from here
<a href="http://downloads.vagrantup.com/">http://downloads.vagrantup.com/</a>

### Install X11 (Mountain Lion only)
If you're running Mountain Lion you need to **install X11 first**, then **logout and log back in**
<a href="http://xquartz.macosforge.org/downloads/SL/XQuartz-2.7.4.dmg">http://xquartz.macosforge.org/downloads/SL/XQuartz-2.7.4.dmg</a>

### Get the BSY Box

You can either checkout this repo with git or download the zip file <a href="https://github.com/triggertoo/bsy_vagrant_box/archive/master.zip">here.</a>

###Share your local drive
Edit the Vagrantfile to map /vagrant to the folder where you have your BSY content

    main_config.vm.share_folder "bsy", "/vagrant", "/Users/nicam/Dropbox/ZHAW/BSY", :nfs => !Kernel.is_windows?


###Run the vagrant box
	cd /Path/to/where/you/put/it
	vagrant up

###Connect to the box

	vagrant ssh
	cd /vagrant

###Open ddd debug with X11 forwarding

	sh open_ddd.sh


