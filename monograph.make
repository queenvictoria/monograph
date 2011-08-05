; what is the difference between make and build ? in the cossey / buildkit example 
; `build` gets drupal core and patches it ( `distro` ) then retrieves the profile 
; and `make` gets contrib modules ( via buildkits drupal-org.make file ) and 
; additions from cossey

; so build would run first
; followed by make

; Build Kit taking over
; ---------------------
; Include Build Kit install profile makefile via URL
includes[] = http://drupalcode.org/project/buildkit.git/blob_plain/refs/heads/7.x-2.x:/drupal-org.make

; content type widgets
projects[link][subdir] = "contrib"
projects[date][subdir] = "contrib"

; utils
projects[views][subdir] = "contrib"
projects[devel][subdir] = "developer"
projects[libraries][subdir] = "contrib"

; social
projects[addthis][subdir] = "contrib"
projects[addthis][version] = "2.1-beta1"

; asset handling
; colorbox & libraries
projects[colorbox][subdir] = "contrib"

libraries[colorbox][download][type] = "get"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/tarball/master"
; libraries[colorbox][download][tag] = v2.1.2
libraries[colorbox][destination] = "libraries"   

; media
