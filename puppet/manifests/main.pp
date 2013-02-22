class apt_update {
    exec { "aptGetUpdate":
        command => "sudo apt-get update",
        path => ["/bin", "/usr/bin"]
    }
}

class ddd {
    package { "ddd":
        ensure => present
    }
	
    package { "make":
        ensure => present
    }
}

class groups {
    group { "puppet":
        ensure => present,
    }
}

include apt_update
include ddd
include groups
