bsy_vagrant_box
===============

# Vagrant Setup
<a href="http://docs.vagrantup.com/v1/docs/getting-started/index.html">http://docs.vagrantup.com/v1/docs/getting-started/index.html</a>

### Install X11 (Mountain Lion only)
If you're running Mountain Lion you need to **install X11 first**, then **logout and log back in**
<a href="http://xquartz.macosforge.org/downloads/SL/XQuartz-2.7.4.dmg">http://xquartz.macosforge.org/downloads/SL/XQuartz-2.7.4.dmg</a>

###Run the vagrant box

	vagrant up

###Open ddd debug with X11 forwarding

	sh open_ddd.sh


###Share your local drive
Edit the Vagrantfile to map /vagrant to the folder where you have your BSY content

    main_config.vm.share_folder "bsy", "/vagrant", "/Users/nicam/Dropbox/ZHAW/BSY", :nfs => !Kernel.is_windows?

###Connect to the box

	vagrant ssh